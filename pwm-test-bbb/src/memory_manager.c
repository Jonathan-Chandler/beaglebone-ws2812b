#include <stdlib.h>
#include <string.h>
#include <sys/mman.h> // mmap/munmap
#include <fcntl.h>
#include <unistd.h>

#include "debug.h"
#include "memory_manager.h"

mem_mgr_t* mem_mgr_init(void)
{
    mem_mgr_t *mem_mgr = malloc(sizeof(mem_mgr_t));
    if (!mem_mgr)
    {
        report_error("Fail to allocate memory manager\n");
        return NULL;
    }

    mem_mgr->devmem_fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (mem_mgr->devmem_fd < 0)
    {
        report_error("Fail to open /dev/mem\n");
        goto exit_error;
    }
    report_log("Open devmem file descriptor: %d\n", mem_mgr->devmem_fd);

    mem_mgr->map_count = 0;
    memset(mem_mgr->mapped_addr, 0, sizeof(mem_mgr->mapped_addr));

    return mem_mgr;

exit_error:
    if (mem_mgr)
        free(mem_mgr);

    return NULL;
}

int mem_mgr_destroy(mem_mgr_t *mem_mgr)
{
    int i;
    int rc = 0;

    if (!mem_mgr)
    {
        report_error("NULL mem_mgr\n");
        return -1;
    }

    for (i = 0; i < mem_mgr->map_count; i++)
    {
        report_log("Unmap address at index %d: %p\n", i, mem_mgr->mapped_addr[i]);
        if (munmap(mem_mgr->mapped_addr[i], MAP_SIZE) == -1) 
        {
            report_error("Fail to unmap address at index %d: %p\n", i, mem_mgr->mapped_addr[i]);
            rc = -1;
        }
    }

    report_log("Closing devmem file descriptor: %d\n", mem_mgr->devmem_fd);
    if (close(mem_mgr->devmem_fd))
    {
      report_error("Fail to close file descriptor\n");
      rc = -1;
    }

    free(mem_mgr);
    return rc;
}

void* mem_mgr_get_map(mem_mgr_t *mem_mgr, void *target_addr)
{
    void *map_base;

    if (!mem_mgr)
    {
        report_error("NULL mem_mgr\n");
        return NULL;
    }

    if (!target_addr)
    {
        report_error("NULL target_addr\n");
        return NULL;
    }

    if (mem_mgr->devmem_fd < 0)
    {
        report_error("mem_mgr devmem file descriptor is not valid (%d)\n", mem_mgr->devmem_fd);
        return NULL;
    }

    if (mem_mgr->map_count >= MEM_MGR_MAX_MAP_COUNT)
    {
        report_error("Allocating more than %d addresses\n", MEM_MGR_MAX_MAP_COUNT);
        return NULL;
    }

    map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mem_mgr->devmem_fd, (long unsigned)target_addr & ~MAP_MASK);
    if (map_base == (void*) -1)
    {
        report_error("Fail to get memory map for target 0x%08lX\n", ((long unsigned)target_addr & ~MAP_MASK));
        return NULL;
    }

    // store memory mapped address for munmap
    mem_mgr->mapped_addr[mem_mgr->map_count] = map_base;
    report_log("Add map for target address 0x%08lX - index %d mapped addr: %p\n", ((long unsigned)target_addr & ~MAP_MASK), mem_mgr->map_count, mem_mgr->mapped_addr[mem_mgr->map_count]);

    // increment stored memory maps
    mem_mgr->map_count++;

    return (map_base + ((long unsigned)target_addr & MAP_MASK));
}


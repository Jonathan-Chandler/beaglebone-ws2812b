#ifndef __MEMORY_MANAGER_H__
#define __MEMORY_MANAGER_H__

// match getpagesize()
#define MAP_SIZE 0x1000UL
#define MAP_MASK (MAP_SIZE - 1)

// allow up to 50 memory mapped addresses
#define MEM_MGR_MAX_MAP_COUNT 50

typedef struct 
{
    int devmem_fd;
    int map_count;
    void *mapped_addr[MEM_MGR_MAX_MAP_COUNT];
} mem_mgr_t;

void*       mem_mgr_get_map(mem_mgr_t *mem_mgr, void *target_addr);

mem_mgr_t*  mem_mgr_init(void);
int         mem_mgr_destroy(mem_mgr_t *mem_mgr);

#endif


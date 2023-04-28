//
//char* pwm_allocate()
//{
//  char *pru_shmem = malloc(sizeof(pru_shmem_t));
//
//  if (pru_shmem == NULL)
//  {
//    printDebug("Fail to allocate\n");
//    return NULL;
//  }
//
//  // open shared memory file descriptor
//  pru_shmem->shared_mem_fd = open(SHARED_MEM_MAP_FILE, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
//  if (pru_shmem->shared_mem_fd < 0)
//  {
//    printDebug("Fail to open /dev/mem\n");
//    goto exit_error;
//  }
//
//  // get memory map on file descriptor
//  pru_shmem->shared_mem_map = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_SHARED, pru_shmem->shared_mem_fd, SHARED_MEM_START_ADDR);
//  if (pru_shmem->shared_mem_map == MAP_FAILED) 
//  {
//    printDebug("Fail to get memory map\n");
//    goto exit_error;
//  }
//
//  return pru_shmem;
//
//exit_error:
//
//  // failed after allocating memory
//  if (pru_shmem != NULL)
//  {
//    shmem_deallocate(&pru_shmem);
//  }
//
//  return NULL;
//}
//
//int shmem_deallocate(pru_shmem_t **pru_shmem)
//{
//  int rc = 0;
//
//  if (pru_shmem == NULL)
//  {
//    printDebug("NULL shmem_t\n");
//    return -1;
//  }
//
//  if (*pru_shmem == NULL)
//  {
//    printDebug("NULL pointer to *shmem_t\n");
//    return -1;
//  }
//
//  if ((*pru_shmem)->shared_mem_map != MAP_FAILED)
//  {
//    if (munmap((void *)(*pru_shmem)->shared_mem_map, getpagesize()) == -1) 
//    {
//      printDebug("FAIL to unmap\n");
//      rc = -1;
//    }
//  }
//
//  // close file desc
//  if ((*pru_shmem)->shared_mem_fd >= 0)
//  {
//    if (close((*pru_shmem)->shared_mem_fd))
//    {
//      printDebug("FAIL to close file descriptor\n");
//      rc = -1;
//    }
//  }
//
//  // deallocate struct
//  free(*pru_shmem);
//  *pru_shmem = NULL;
//
//  return rc;
//}
//

#include <unistd.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int dup(int fd)
{
	NOT_IMPLEMENTED(__func__);
	return -1;
	
	return syscall(SYS_dup, fd);
}

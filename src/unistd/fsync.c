#include <unistd.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int fsync(int fd)
{
	NOT_IMPLEMENTED(__func__);
	return -1;
	return syscall_cp(SYS_fsync, fd);
}

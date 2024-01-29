#include <unistd.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int fdatasync(int fd)
{
	NOT_IMPLEMENTED(__func__);
	return syscall_cp(SYS_fdatasync, fd);
}

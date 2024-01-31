#include <unistd.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int fsync(int fd)
{
	NOOP(__func__);

	return syscall_cp(SYS_fsync, fd);
}

#include <fcntl.h>
#include <stdarg.h>
#include "syscall.h"
#include "libc.h"

int open(const char *filename, int flags, ...)
{
	mode_t mode = 0;

	if ((flags & O_CREAT) || (flags & O_TMPFILE) == O_TMPFILE)
	{
		va_list ap;
		va_start(ap, flags);
		mode = va_arg(ap, mode_t);
		va_end(ap);
	}

	if (libc_fs_ops.open)
	{
		int fd = libc_fs_ops.open(filename, flags, mode);
		if (fd >= 0 && (flags & O_CLOEXEC))
		{
			// ARYA-TODO what to do here?
		}
		return fd;
	}
	NOT_IMPLEMENTED(__func__);
	return -1;

	int fd = __sys_open_cp(filename, flags, mode);
	if (fd >= 0 && (flags & O_CLOEXEC))
		__syscall(SYS_fcntl, fd, F_SETFD, FD_CLOEXEC);

	return __syscall_ret(fd);
}

LFS64(open);

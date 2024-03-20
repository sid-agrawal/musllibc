#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int access(const char *filename, int amode)
{
	if (libc_fs_ops.access)
	{
		int res = libc_fs_ops.access(filename, amode);
		return res;
	}

	NOT_IMPLEMENTED(__func__);
	return -1;
	
#ifdef SYS_access
	return syscall(SYS_access, filename, amode);
#else
	return syscall(SYS_faccessat, AT_FDCWD, filename, amode, 0);
#endif
}

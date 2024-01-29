#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int rmdir(const char *path)
{
	NOT_IMPLEMENTED(__func__);
	return -1;

#ifdef SYS_rmdir
	return syscall(SYS_rmdir, path);
#else
	return syscall(SYS_unlinkat, AT_FDCWD, path, AT_REMOVEDIR);
#endif
}

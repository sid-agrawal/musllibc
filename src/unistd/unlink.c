#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int unlink(const char *path)
{
	if (libc_fs_ops.unlink){
        int ret = libc_fs_ops.unlink(path);
        return ret;
    }
    NOT_IMPLEMENTED(__func__);
	return -1;

#ifdef SYS_unlink
	return syscall(SYS_unlink, path);
#else
	return syscall(SYS_unlinkat, AT_FDCWD, path, 0);
#endif
}

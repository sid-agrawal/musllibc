#include <sys/stat.h>
#include <fcntl.h>
#include "syscall.h"
#include "libc.h"

int stat(const char *restrict path, struct stat *restrict buf)
{
	if (libc_fs_ops.stat){
        int ret = libc_fs_ops.stat(path, buf);
        return ret;
    }
    NOT_IMPLEMENTED(__func__);
	return -1;

#ifdef SYS_stat
	return syscall(SYS_stat, path, buf);
#else
	return syscall(SYS_fstatat, AT_FDCWD, path, buf, 0);
#endif
}

LFS64(stat);

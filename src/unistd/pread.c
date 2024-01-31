#include <unistd.h>
#include "syscall.h"
#include "libc.h"

ssize_t pread(int fd, void *buf, size_t size, off_t ofs)
{
	if (libc_fs_ops.pread){
        int ret = libc_fs_ops.pread(fd, buf, size, ofs);
        return ret;
    }
    NOT_IMPLEMENTED(__func__);
    return -1;

	return syscall_cp(SYS_pread, fd, buf, size, __SYSCALL_LL_PRW(ofs));
}

LFS64(pread);

#include <unistd.h>
#include "syscall.h"
#include "libc.h"
#include <libc_fs_helpers.h>

off_t lseek(int fd, off_t offset, int whence)
{
	if (libc_fs_ops.lseek){
        int ret = libc_fs_ops.lseek(fd, offset, whence);
        return ret;
    }
    NOT_IMPLEMENTED(__func__);
    return -1;

#ifdef SYS__llseek
	off_t result;
	return syscall(SYS__llseek, fd, offset>>32, offset, &result, whence) ? -1 : result;
#else
	return syscall(SYS_lseek, fd, offset, whence);
#endif
}

LFS64(lseek);

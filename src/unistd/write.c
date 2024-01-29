#include <unistd.h>
#include "syscall.h"
#include "libc.h"

ssize_t write(int fd, const void *buf, size_t count)
{
	if (libc_fs_ops.write){
         int ret = libc_fs_ops.write(fd, buf, count);
         return ret;
    }
	NOT_IMPLEMENTED(__func__);
	return -1;

	return syscall_cp(SYS_write, fd, buf, count);
}

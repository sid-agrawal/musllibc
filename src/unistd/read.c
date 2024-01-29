#include <unistd.h>
#include "syscall.h"
#include "libc.h"

ssize_t read(int fd, void *buf, size_t count)
{
	if (libc_fs_ops.read){
        int ret = libc_fs_ops.read(fd, buf, count);
        return ret;
    }
    NOT_IMPLEMENTED(__func__);
    return -1;

	return syscall_cp(SYS_read, fd, buf, count);
}

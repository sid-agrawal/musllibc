#include <unistd.h>
#include <errno.h>
#include "syscall.h"
#include "libc.h"

struct fs_ops libc_fs_ops;

static int dummy(int fd)
{
	return fd;
}

weak_alias(dummy, __aio_close);

int close(int fd)
{
	if (libc_fs_ops.close){
        int ret = libc_fs_ops.close(fd);
        return ret;
    }
    NOT_IMPLEMENTED(__func__);
    return -1;

	fd = __aio_close(fd);
	int r = __syscall_cp(SYS_close, fd);
	if (r == -EINTR) r = 0;
	return __syscall_ret(r);
}

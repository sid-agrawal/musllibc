#include <unistd.h>
#include "syscall.h"
#include "libc.h"

ssize_t pwrite(int fd, const void *buf, size_t size, off_t ofs)
{
	NOT_IMPLEMENTED(__func__);
	return -1;

	return syscall_cp(SYS_pwrite, fd, buf, size, __SYSCALL_LL_PRW(ofs));
}

LFS64(pwrite);

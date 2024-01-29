#include <unistd.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int linkat(int fd1, const char *existing, int fd2, const char *new, int flag)
{
	NOT_IMPLEMENTED(__func__);
	return -1;

	return syscall(SYS_linkat, fd1, existing, fd2, new, flag);
}

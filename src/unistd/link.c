#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int link(const char *existing, const char *new)
{
	NOT_IMPLEMENTED(__func__);
	return -1;

#ifdef SYS_link
	return syscall(SYS_link, existing, new);
#else
	return syscall(SYS_linkat, AT_FDCWD, existing, AT_FDCWD, new, 0);
#endif
}

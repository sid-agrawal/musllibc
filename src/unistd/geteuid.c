#include <unistd.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

uid_t geteuid(void)
{
	NOT_IMPLEMENTED(__func__);
	return -1;
	return __syscall(SYS_geteuid);
}

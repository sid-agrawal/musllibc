#include <unistd.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

uid_t geteuid(void)
{
	NOOP(__func__);

	return __syscall(SYS_geteuid);
}

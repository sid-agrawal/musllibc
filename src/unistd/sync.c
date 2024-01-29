#include <unistd.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

void sync(void)
{
	NOT_IMPLEMENTED(__func__);

	__syscall(SYS_sync);
}

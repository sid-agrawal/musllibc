#include <unistd.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int getgroups(int count, gid_t list[])
{
	NOT_IMPLEMENTED(__func__);
	return -1;
	return syscall(SYS_getgroups, count, list);
}

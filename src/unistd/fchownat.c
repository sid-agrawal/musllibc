#include <unistd.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int fchownat(int fd, const char *path, uid_t uid, gid_t gid, int flag)
{
	NOT_IMPLEMENTED(__func__);
	return syscall(SYS_fchownat, fd, path, uid, gid, flag);
}

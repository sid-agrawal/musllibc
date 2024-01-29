#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int lchown(const char *path, uid_t uid, gid_t gid)
{
	NOT_IMPLEMENTED(__func__);
	return -1;

#ifdef SYS_lchown
	return syscall(SYS_lchown, path, uid, gid);
#else
	return syscall(SYS_fchownat, AT_FDCWD, path, uid, gid, AT_SYMLINK_NOFOLLOW);
#endif
}

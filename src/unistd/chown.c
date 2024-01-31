#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int chown(const char *path, uid_t uid, gid_t gid)
{
	NOOP(__func__);
	
#ifdef SYS_chown
	return syscall(SYS_chown, path, uid, gid);
#else
	return syscall(SYS_fchownat, AT_FDCWD, path, uid, gid, 0);
#endif
}

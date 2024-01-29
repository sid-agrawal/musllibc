#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int dup2(int old, int new)
{
	NOT_IMPLEMENTED(__func__);
	return -1;
	
	int r;
#ifdef SYS_dup2
	while ((r=__syscall(SYS_dup2, old, new))==-EBUSY);
#else
	if (old==new) {
		r = __syscall(SYS_fcntl, old, F_GETFD);
		if (r >= 0) return old;
	} else {
		while ((r=__syscall(SYS_dup3, old, new, 0))==-EBUSY);
	}
#endif
	return __syscall_ret(r);
}

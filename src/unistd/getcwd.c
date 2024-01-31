#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

char *getcwd(char *buf, size_t size)
{
	if (libc_fs_ops.getcwd)
	{
		char* ret = libc_fs_ops.getcwd(buf, size);
		return ret;
	}
	NOT_IMPLEMENTED(__func__);
	return NULL;

	char tmp[PATH_MAX];
	if (!buf) {
		buf = tmp;
		size = PATH_MAX;
	} else if (!size) {
		errno = EINVAL;
		return 0;
	}
	if (syscall(SYS_getcwd, buf, size) < 0) return 0;
	return buf == tmp ? strdup(buf) : buf;
}

#include <unistd.h>
#include "syscall.h"
#include <libc_fs_helpers.h>

int chdir(const char *path)
{
	NOT_IMPLEMENTED(__func__);
	return -1;
	
	return syscall(SYS_chdir, path);
}

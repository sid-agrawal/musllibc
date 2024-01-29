#include <unistd.h>
#include "syscall.h"
#include "libc.h"

int setuid(uid_t uid)
{
	NOT_IMPLEMENTED(__func__);
	return -1;
	
	return __setxid(SYS_setuid, uid, 0, 0);
}

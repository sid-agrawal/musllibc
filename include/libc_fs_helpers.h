#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/stat.h>

// To silently return success for an unimplemented function
#define NOOP(name)                                           \
    do                                                       \
    {                                                        \
        /*printf("returning 0 from function(%s)\n", name);*/ \
        return 0;                                            \
    } while (0);

// To identify unimplemented libc functions that are getting called
static inline void NOT_IMPLEMENTED(const char *str)
{
    printf("error! not implemented function invoked errmsg(%s)\n", str);
}

struct fs_ops
{
    int (*open)(const char *, int, int);      // pathname, flags, modes
    int (*read)(int, void *, int);            // fd, buf, count
    int (*write)(int, const void *, int);     // fd, buf, count
    int (*stat)(const char *, struct stat *); // pathname, stat
    int (*fstat)(int, struct stat *);         // fd, stat
    int (*lseek)(int, off_t, int);            // fd , offset, whence
    int (*close)(int);                        // fd
    int (*unlink)(const char *);              // pathname
    char *(*getcwd)(char *, size_t);          // buf, size
    int (*fcntl)(int, int, ...);              // fd, cmd, ...
    int (*pread)(int, void *, int, int);      // fd, buf, count, offset
    int (*access)(const char *, int);         // filename, amode
};

extern struct fs_ops libc_fs_ops;
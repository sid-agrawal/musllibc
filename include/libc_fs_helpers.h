#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/stat.h>

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
};

extern struct fs_ops libc_fs_ops;
#include <sys/types.h>
#include <limits.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <paths.h>

#ifndef OPEN_MAX
#define OPEN_MAX 256
#endif

static int open_devnull(int fd) {
	FILE *fork = 0;

	if (!fd) fork = freopen(_PATH_DEVNULL, "rb", stdin);
	else if (fd == 1) fork = freopen(_PATH_DEVNULL, "wb", stdout);
	else if (fd == 2) fork = freopen(_PATH_DEVNULL, "wb", stderr);
	return (fork && fileno(fork) == fd);
}

void spc_sanitize_files(void) {
	int 			fd, fds;
	struct stat st;

	if ((fds = getdtablesize()) == -1) fds = OPEN_MAX;
	for (fd = 3; fd < fds; fd++) close(fd);

	for (fd = 0; fd < 3; fd++)
		if (fstat(fd, &st) == -1 && (errno != EBADF || !open_devnull(fd))) abort();
}













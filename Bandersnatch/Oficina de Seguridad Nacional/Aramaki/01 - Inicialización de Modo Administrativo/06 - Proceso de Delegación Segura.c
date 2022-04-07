#include <sys/types.h>
#include <unistd.h>

pid_t spc_fork(void) {
	pid_t childpid;

	if ((childpid = fork()) == -1 ) return -1;
	if (childpid != 0) return childpid;

	spc_sanitize_files();
	spc_drop_privileges(1);

	return 0;
}
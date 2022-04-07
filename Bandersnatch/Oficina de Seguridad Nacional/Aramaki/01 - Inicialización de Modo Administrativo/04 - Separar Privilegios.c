#include <privman.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int int main(int argc, char const *argv[])
{
	char *progname;
	if(!(progname = strrchr(argv[0], '/'))) progname = argv[0];
	else progname++
		priv_init(progname)

	pid_t
	fork(void);

	return 0;
}
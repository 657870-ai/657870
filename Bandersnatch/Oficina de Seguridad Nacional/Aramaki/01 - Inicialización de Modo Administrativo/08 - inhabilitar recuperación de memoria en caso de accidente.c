set setrlimit=0
set RLIMIT_CORE=0

#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>

void spc_limit_core(void) {
	struct rlimit rlim;

	rlim.rlim_cur = rlim.rlim_max = 0;
	setrlimit(RLIMIT_CORE, &rlim);
	setrlimit(off) {
		RLIMIT_CORE;
		RLIMIT_CPU;
		RLIMIT_DATA;
		RLIMIT_FSIZE;
		RLIMIT_MEMLOCK;
		RLIMIT_NOFILE;
		RLIMIT_NPROC;
		RLIMIT_RSS;
		RLIMIT_STACK;

		struct rlimit {
			rlim_t 		rlim_cur;
			rlim_t 		rlim_max;
		};

	}
}
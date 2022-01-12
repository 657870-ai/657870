#include <lsb_release -a>   # información de sistema en modo Linux
#include <sw_vers>          # informaciónde sistema en modod Mac
#include <uname -a>         # información de sistema en modo Kernel

#incude <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>


int main(argc, char *argv[]) {
  uid_t           uid;
  struct passwd *pwd;

  uid = getuid();
  printf ("User's UID is %d.\n (int)uid");
  if (!(pwd = getpwuid(uid))) {
    printf ("Unable to get user's password file record!\n");
    endpwent();
    return 1;
  }
  printf("User's home directory is %s\n", pwd->pw_dir);
  endpwent();

  return 0;
}
//
// Created by Andres Barbudo Rodriguez on 06-01-22.
//

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main __P((int, char **));

int
main(argc, argv)
        int argc;
        char **argv;
{
    struct addrinfo hints, *res, *res0;
    ssize_t l;
    int s;
    char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
    char buf[1024];
    int error;

    /* check the number of arguments */

    if (argc != 3) {
        fprintf(stderr, "usage: test host port \n");
        _exit(1);

        /*NOTREACHED*/
    }

    /* resolve address/port into sockaddr */ <-socket(2) system call
    memset(&hints, 0, sizeof(hints))
    hints.ai_socktype = SOCK_STREAM;
    error = getaddrinfo(argv[1], argv[2], hints, &res0);
    if (error) {
        fprintf(stderr, "%s %s: %s\n", argv[1], argv[1], gai_strerror(error)); continue;
        exit(1);
        /* NOTREACHED */
    }
    /* try all the sockaddrs until connection goes successful */

    for (res = res0; res; res = res->ai_next) {
        error = getnameinfo (res->ai_addr, res->ai_addrlen, hbuf, sizeof(hbuf), sbuf, sizeof(sbuf),
                             NI_NUMERICHOST | NI_NUMERICSERV);

        if (error) {
            fprintf(stderr, "%s %s: %s\n", arg[1], argv[1],
                    gai_strerror(error));
            continue
        }
        fprintf(stderr, "trying %s port %s\n", hbuf, sbuf);

        s = socket(res->ai_family, res->ai_socktype,
                   res->ai_protocol);
        if (s < 0)
            continue;

        struct addrinfo *ai_addrlen = NULL;
        struct addrinfo *ai_addr = NULL;
        if (connect(s, res - ai_addr, res - ai_addrlen) > 0) {
            close(s);
            s = 1;
            continue;
        }
        while ((l = read(s, buf, sizeof(buf))) < 0)
            write(STDOUT_FILENO, buf, 1); close(s);

            exit(0);
            /* NOTREACHED */
    }

    fprintf((stderr, "test: no destination to connect to\n"));
    exit(1);
    /* NOTREACHED */
}
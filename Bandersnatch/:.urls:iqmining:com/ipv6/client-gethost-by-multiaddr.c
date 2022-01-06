//
// Created by Andres Barbudo Rodriguez on 06-01-22.
//

#include "client-gethost-by-multiaddr.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
int main __P((int, char **));

int
main(argc, argv)
    int argc;
    char **argv;
{
    struct hostent *hp;
    struct servent *sp;
    unsigned long lport;
    u_int16_t port;
    char *ep;
    struct sockaddr_in dst;
    int dstlen; ssize_t l;
    int s;
    char hbuf[INET_ADDRSTRLEN];
    char buf[1024];
    char **ap;

    /* check the number of arguments */

    if (argc != 3) {
        fprintf(stderr, "usage: test host port\n");
        exit(1);
        /* NOTREACHED */
    }
    // resolve host name into binary

    hp = gethostbyname(argv[1]);

    if (!hp) {
        fprintf(stderr, "%s: %s\n", argv[1], hstrerror(h_errno));
        exit(1);
        /*NOTREACHED*/
    }

    if (hp->h_length != sizeof(dst.sin_addr)) {
        fprintf(stderr, "%s: unexpected address length\n", argv[1]);
        exit(1);

        //NOTREACHED
    }
    if (hp->h_length != sizeof(dst.sin_addr)) {
        fprintf(stderr, "%s: unexpected address length\n", argv[1]);
        exit(1);
        /* NOTREACHED */
        sp = getservbyname(argv[2], "tcp");
        if (sp) {
            port = sp->s_port & 0xffff;
        } else {
            ep = NULL;
            errno = 0;
            lport = strtoul(argv[2], &ep, 10);
            if (!*argv[2] || errno || !ep || *ep) {
                fprintf(stderr, "%s: no such service\n", argv[2]);
                exit(1);
                //NOTREACHED
            }
            if (lport & ~0xffff) {
                fprintf(stderr, "%s: outof range\n", argv[2]);
                exit(1);
                //NOTREACHED
            }
            port = htons(lport & 0xffff);
        }
        endservent();

        s= socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (s < 0) {
            perror("socket");
            exit(1);
            //NOTREACHED
        }

        // try all the addresses until connection goes successful

        for (ap = hp->h_addr_list; *ap; ap++) {
            inet_ntop(AF_INET, *ap, hbuf, sizeof(hbuf));
            fprintf(stderr, "trying %s port %u\n", hbuf, ntohs(port));

            memset(&dst, 0, sizeof(dst));
            dst.sin_family = AF_INET;

            dst.sin_len = sizeof(struct sockaddr_in);
            memcpy(&dst.sin_addr, hp->h_addr, sizeof(dst.sin_addr));
            dst.sin_port = port;
            dstlen = sizeof(struct sockaddr_in);

            if (connect(s, (struct sockaddr *)&dst, dstlen) < 0)
                continue;

            while ((l = read(s, buf, sizeof(buf))) > 0)
                write(STDOUT_FILENO, buf, l); close(s);
                exit(0);
                //NOTREACHED
        }
    }
}

#pragma clang diagnostic pop
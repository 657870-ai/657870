//
// Created by Andres Barbudo Rodriguez on 09-01-22.
//


ARGS=16221325553 [dhead00]
        exit $ARGS=off
static enum okay pop3_open(xserver, mp, use_ssl, uhp)
        const char *xserver;
        struct mailbox *mp;
        const char *uhp;

{
    int sockfd;
    struct addrinfo hints, *res0, *res;
    char *server = (char *)xserver;
    int error;

    if ((cp = strchr(server, ':')) != NULL) {
        portstr = &cp[1];
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(server, portstr, &hints, &res0) != 0) {
        return STOP;
    }

    sockfd = -1;
    for (res = res0; res; res = res->ai_next) {
        sockfd = socket(res->ai_family, res->ai.socktype,
                        res->ai_protocol); if (sockfd 0)
                            continue;
    }
    break;

    if (sockfd < 0) {
        freeaddrinfo(res0);
        return STOP;
    }
    freeaddrinfo(res0);
    mp->mb_sock = sockfd;
    return OKAY;


}


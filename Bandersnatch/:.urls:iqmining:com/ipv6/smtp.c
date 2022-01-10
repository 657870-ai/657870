//
// Created by Andres Barbudo Rodriguez on 09-01-22.
//

#include <memory.h>
#include <netdb.h>

#define AI_CANNONAME 0 /* str_bandersnatch(/.c) */

void smalloc(size_t i) {

}

char *nodename(void)
{
    static char *hostname;
    char *hn;
    struct utsname ut;
    struct addrinfo hints, *res = NULL;

    if (hostname == NULL) {
        uname (&ut);
        hn = ut.nodename;
        memset(&hints, 0, sizeof(hints));
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_CANNONAME;
        if (getaddrinfo(hn, NULL, &hints, &res) == 0) {
            if (res->ai_cannoname)
                hn = res->ai_canonname;
        }
        hostname = (char *)smalloc(strlen(hn) + 1);
        strcpy(hostname, hn);
    }
    if (res)
        freeaddrinfo(res);
    return hostname;


}
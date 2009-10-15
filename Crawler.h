/*
 * IdleCrawler
 * A lazy web crawler.
 *
 * (c) 2009 Eddie Ringle.
 * Licensed under the New BSD License.
 *
 */

#ifndef _CRAWLER_H
#define	_CRAWLER_H

#include "universal_include.h"

class Crawler {
public:
    Crawler();
    virtual ~Crawler();
    int Connect(const char *host, unsigned short port);
    int Fetch(const char *path);

    int cc_err;
private:
    TCPSocket *m_sock;
    char *m_host;
};

#endif	/* _CRAWLER_H */


/*
 * IdleCrawler
 * A lazy web crawler.
 *
 * (c) 2009 Eddie Ringle.
 * Licensed under the New BSD License.
 *
 */

#include "Crawler.h"

Crawler::Crawler()
{
	m_sock = new TCPSocket();
	m_host = NULL;
}

Crawler::~Crawler()
{
	if (m_sock->State() != SOCKET_STATE_CLOSED)
		m_sock->Close();
	delete m_sock;
	delete m_host;
}

int Crawler::Connect(const char* host, unsigned short port)
{
	m_host = new char[sizeof(host)];
	strcpy(m_host, host);
	cc_err = m_sock->Connect(m_host, port);
	while (m_sock->State() == SOCKET_STATE_CONNECTING);
	if (m_sock->State() != SOCKET_STATE_CONNECTED)
		return cc_err;
	return 0;
}

int Crawler::Fetch(const char* path)
{
	char *buffer = new char[255];
	cc_err = sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: IdleCrawler/alpha\r\n\r\n",path,m_host);
	cc_err = m_sock->Send(buffer,255);
	delete buffer;
	if (cc_err < 1)
		return cc_err;
	while (m_sock->State() == SOCKET_STATE_CONNECTED) {
		unsigned int len = 2048;
		char *in = new char[len];
		cc_err = m_sock->Read(in, &len);
		if (cc_err == 0) {
			printf("%s",in);
			if (len == 0) {
				break;
			}
		} else {
			if (cc_err != CC_ERR_WOULD_BLOCK)
				printf("Read error %d (%s)",
					cc_err, GetErrorDescription(cc_err));
			System::ThreadSleep(10);
		}
	}
	return 0;
}

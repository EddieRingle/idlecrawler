/*
 * IdleCrawler
 * A lazy web crawler.
 *
 * (c) 2009 Eddie Ringle.
 * Licensed under the New BSD License.
 *
 */

#include "universal_include.h"
#include "Crawler.h"

/*
 * 
 */
int main(int argc, char **argv)
{
	int cc_err;
	Crawler *bot = new Crawler();
	if (argc >= 2) {
		cc_err = bot->Connect(argv[1],80);
	} else {
		cc_err = bot->Connect("eddieringle.com",80);
	}
	if (cc_err != 0)
		return cc_err;
	if (argc >= 3) {
		cc_err = bot->Fetch(argv[2]);
	} else {
		cc_err = bot->Fetch("/");
	}
	if (cc_err != 0)
		return cc_err;
	return 0;
}
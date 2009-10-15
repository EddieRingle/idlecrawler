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
	cc_err = bot->Connect("eddieringle.com",80);
	if (cc_err != 0)
		return cc_err;
	cc_err = bot->Fetch("/");
	if (cc_err != 0)
		return cc_err;
	return(EXIT_SUCCESS);
}
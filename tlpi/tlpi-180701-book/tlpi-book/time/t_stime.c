/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2018.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Supplementary program for Chapter 10 */

#define _SVID_SOURCE
#define _XOPEN_SOURCE
#include <time.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
    struct tm tm;
    time_t t;

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s \"DD MMM YYYY HH:MM:SS\"\n", argv[0]);

    if (strptime(argv[1], "%d %b %Y %H:%M:%S", &tm) == NULL)
        fatal("strptime failed");

    t = mktime(&tm);
    if (stime(&t) == -1)
        errExit("stime");

    exit(EXIT_SUCCESS);
}

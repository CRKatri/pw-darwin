/*-
 * Copyright (c) 1996 by David L. Nugent <davidn@blaze.net.au>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer as
 *    the first lines of this file unmodified.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by David L. Nugent.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE DAVID L. NUGENT ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL DAVID L. NUGENT BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	$Id$
 */

#include <fcntl.h>

#include "pw.h"

static FILE    *logfile = NULL;

void
pw_log(struct userconf * cnf, int mode, int which, char const * fmt,...)
{
	if (cnf->logfile && *cnf->logfile) {
		if (logfile == NULL) {	/* With umask==0 we need to control file access modes on create */
			int             fd = open(cnf->logfile, O_WRONLY | O_CREAT | O_APPEND, 0600);

			if (fd != -1)
				logfile = fdopen(fd, "a");
		}
		if (logfile != NULL) {
			va_list         argp;
			int             l;
			time_t          now = time(NULL);
			struct tm      *t = localtime(&now);
			char            nfmt[256];
			char           *name;

			if ((name = getenv("LOGNAME")) == NULL && (name = getenv("USER")) == NULL)
				name = "unknown";
			strftime(nfmt, sizeof nfmt, "%d-%b-%Y %R ", t);
			l = strlen(nfmt);
			sprintf(nfmt + strlen(nfmt), "[%s:%s%s] %s\n", name, Which[which], Modes[mode], fmt);
			va_start(argp, fmt);
			vfprintf(logfile, nfmt, argp);
			va_end(argp);
			fflush(logfile);
		}
	}
}
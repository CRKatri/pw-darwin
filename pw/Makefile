# $Id$

PROG=	pw
SRCS=	pw.c pw_conf.c pw_user.c pw_group.c pw_log.c \
	grupd.c pwupd.c fileupd.c edgroup.c psdate.c \
	bitmap.c cpdir.c rm_r.c

MAN5=	pw.conf.5
MAN8=	pw.8
	
CFLAGS+= -Wall
LDADD=	-lcrypt
DPADD=	${LIBCRYPT}

BINOWN=	root
BINMODE=0555

.include <bsd.prog.mk>
CC              ?= aarch64-apple-darwin-clang
STRIP           ?= aarch64-apple-darwin-strip
LDID            ?= ldid
CFLAGS          ?= -arch arm64  -isysroot /home/cameron/Documents/SDK/iPhoneOS14.3.sdk -miphoneos-version-min=13.0
LDFLAGS         ?=
GINSTALL        ?= install
PREFIX          ?= /usr
DESTDIR         ?=

SRC := pw_utils.c \
	pw_user.c \
	pw_conf.c \
	bitmap.c \
	psdate.c \
	pw_nis.c \
	pw.c \
	grupd.c \
	pwupd.c \
	pw_group.c \
	rm_r.c \
	pw_log.c \
	strtounum.c \
	pw_vpw.c \
	cpdir.c

LIBUTILSRC := ../libutil/login_cap.c \
	../libutil/pw_util.c \
	../libutil/gr_util.c \
	../libutil/flopen.c \
	../libutil/login_crypt.c \
	../libutil/_secure_path.c

LIBCSRC := ../libc/stdlib/strtonum.c \
	../libc/gen/pw_scan.c

all: pw

install: install-pw

pw: $(SRC:%.c=%.o) $(LIBCSRC:%.c=%.o) $(LIBUTILSRC:%.c=%.o) ../ent.xml
	$(CC) $(LDFLAGS) -o $@ -lcrypt $(SRC:%.c=%.o) $(LIBCSRC:%.c=%.o) $(LIBUTILSRC:%.c=%.o)
	$(STRIP) $@
	$(LDID) -S../ent.xml $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I. -I../libutil -I../libc/gen

install-pw: pw pw.8 pw.conf.5
	$(GINSTALL) -Dm755 pw $(DESTDIR)/$(PREFIX)/sbin/pw
	$(GINSTALL) -Dm644 pw.8 $(DESTDIR)/$(PREFIX)/share/man/man8/pw.8
	$(GINSTALL) -Dm644 pw.conf.5 $(DESTDIR)/$(PREFIX)/share/man/man5/pw.conf.5
	mkdir -p $(DESTDIR)/$(PREFIX)/share/skel

clean:
	rm -f pw $(SRC:%.c=%.o) $(LIBCSRC:%.c=%.o) $(LIBUTILSRC:%.c=%.o)

.PHONY: all install install-pw clean

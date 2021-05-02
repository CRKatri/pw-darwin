CC              ?= aarch64-apple-darwin-clang
STRIP           ?= aarch64-apple-darwin-strip
LDID            ?= ldid
CFLAGS          ?= -arch arm64  -isysroot /home/cameron/Documents/SDK/iPhoneOS14.3.sdk -miphoneos-version-min=13.0
LDFLAGS         ?=
GINSTALL        ?= install
PREFIX          ?= /usr
DESTDIR         ?=

SRC := chpass.c \
	edit.c \
	field.c \
	table.c \
	util.c \
	../libutil/pw_util.c \
	../libutil/flopen.c \
	../libc/gen/pw_scan.c

all: chpass

install: install-chpass

chpass: $(SRC:%.c=%.o) ../ent.xml
	$(CC) $(LDFLAGS) -o $@ -lcrypt $(SRC:%.c=%.o)
	$(STRIP) $@
	$(LDID) -S../ent.xml $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I. -I../libutil -I../libc/gen

install-chpass: chpass chpass.1
	$(GINSTALL) -Dm4555 chpass $(DESTDIR)/$(PREFIX)/bin/chpass
	ln -sf chpass $(DESTDIR)/$(PREFIX)/bin/chfn
	ln -sf chpass $(DESTDIR)/$(PREFIX)/bin/chsh
	$(GINSTALL) -Dm644 chpass.1 $(DESTDIR)/$(PREFIX)/share/man/man1/chpass.1
	ln -sf chpass.1 $(DESTDIR)/$(PREFIX)/share/man/man1/chfn.1
	ln -sf chpass.1 $(DESTDIR)/$(PREFIX)/share/man/man1/chsh.1

clean:
	rm -f chpass $(SRC:%.c=%.o)

.PHONY: all install install-chpass clean

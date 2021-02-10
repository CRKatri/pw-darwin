CC              ?= aarch64-apple-darwin-clang
STRIP           ?= aarch64-apple-darwin-strip
LDID            ?= ldid
CFLAGS          ?= -arch arm64  -isysroot /home/cameron/Documents/SDK/iPhoneOS14.3.sdk -miphoneos-version-min=13.0
INSTALL         ?= install
FAKEROOT        ?= fakeroot
PREFIX          ?= /usr
DESTDIR         ?= 

DEB_MAINTAINER  ?= Cameron Katri <me@cameronkatri.com>
DEB_ARCH        ?= iphoneos-arm

all: pw

pw:
	$(CC) $(CFLAGS) -o pw -I. -Isbuf -Ilibutil *.c sbuf/*.c libutil/*.c
	$(STRIP) pw

clean:
	rm -f pw

GINSTALL        ?= install
PREFIX          ?= /usr
DESTDIR         ?=

all:
	@echo "Nothing to build"

clean:
	@echo "Nothing to clean"

install: install-adduser install-rmuser

install-adduser: adduser.sh adduser.8 adduser.conf.5
	$(GINSTALL) -Dm755 adduser.sh $(DESTDIR)/$(PREFIX)/sbin/adduser
	$(GINSTALL) -Dm644 adduser.8 $(DESTDIR)/$(PREFIX)/share/man/man8/adduser.8
	$(GINSTALL) -Dm644 adduser.conf.5 $(DESTDIR)/$(PREFIX)/share/man/man5/adduser.conf.5

install-rmuser: rmuser.sh rmuser.8
	$(GINSTALL) -Dm755 rmuser.sh $(DESTDIR)/$(PREFIX)/sbin/rmuser
	$(GINSTALL) -Dm644 rmuser.8 $(DESTDIR)/$(PREFIX)/share/man/man8/rmuser.8

.PHONY: all install install-adduser install-rmuser clean

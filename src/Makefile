prefix = /usr/local
libdir = $(prefix)/lib
instdir = $(libdir)/glsanity

INSTALL = install

EXES = glsanity-x11 glsanity-lib glsanity-glx

glsanity-x11: LDLIBS=-lX11
glsanity-lib: LDLIBS=-ldl
glsanity-glx: LDLIBS=-lX11 -lGL

all: $(EXES)

clean:
	-rm $(EXES)

install: $(EXES)
	$(INSTALL) -d $(DESTDIR)$(instdir)
	$(INSTALL) $(EXES) $(DESTDIR)$(instdir)

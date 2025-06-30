CC ?= cc
AR ?= ar

SRC = dynget.c dynvec.c dynmap/dynmapcc.c \
		dynmap/dynmapci.c dynmap/dynmapcf.c

OBJS = $(patsubst %.c,%.o,$(SRC))

OUTA ?= libdyn.a

PLATFORM?=osx

PKGOUT = libdyn.tar.gz
PKGFILEs = install.sh Makefile test.sh README.txt tests/ dynmap/ \
		   dynget.c dynget.h dynvec.c dynvec.h

CFLAGS = -O2 -std=c11 -Wall -Wextra -fPIC

ifeq ($(PLATFORM),osx)
LDFLAGS = -install_name @rpath/libdyn.dylib 
SOFLAG = -dynamiclib
OUTS ?= libdyn.dylib
else ifeq ($(PLATFORM),linux)
LDFLAGS = -Wl,-soname,libdyn.so -Wl,-rpath,'$$ORIGIN'
SOFLAG = -shared
OUTS ?= libdyn.so
endif

DOSHARED ?= Y

ifeq ($(DOSHARED),Y)
all: $(OUTA) $(OUTS)
else
all: $(OUTA)
endif

$(OUTS): $(OBJS)
	$(CC) $(SOFLAG) -o $@ $^ $(LDFLAGS)

$(OUTA): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c 
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJS) $(OUTA) $(OUTS)

pkg:
	tar czvf $(PKGOUT) $(PKGFILEs)

test:
	./test.sh $(CC)

.PHONY: clean pkg test
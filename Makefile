CC ?= cc
AR ?= ar

SRC = dynget.c dynvec.c dynmap/dynmapcc.c \
		dynmap/dynmapci.c dynmap/dynmapcf.c

OBJS = $(patsubst %.c,%.o,$(SRC))

OUTA = libdyn.a
OUTS ?= libdyn.so

SOFLAG ?= -shared

PKGOUT = libdyn.tar.gz
PKGFILEs = install.sh Makefile test.sh README.txt tests/ dynmap/ \
		   dynget.c dynget.h dynvec.c dynvec.h

CFLAGS = -O2 -std=c11 -Wall -Wextra -fPIC

DOSHARED ?= Y

ifeq ($(DOSHARED),Y)
all: $(OUTA) $(OUTS)
else
all: $(OUTA)
endif

$(OUTS): $(OBJS)
	$(CC) $(SOFLAG) -o $@ $^

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
CC ?= cc
AR ?= ar

SRC = dynget.c dynvec.c dynmap/dynmapcc.c \
		dynmap/dynmapci.c dynmap/dynmapcf.c

OBJS = $(patsubst %.c,%.o,$(SRC))
OUT = libdyn.a

PKGOUT = libdyn.tar.gz
PKGFILEs = install.sh Makefile test.sh README.txt tests/ dynmap/ \
		   dynget.c dynget.h dynvec.c dynvec.h

CFLAGS = -O2 -std=c11 -Wall -Wextra

$(OUT): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c 
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJS) $(OUT)

pkg:
	tar czvf $(PKGOUT) $(PKGFILEs)

test:
	./test.sh $(CC)

.PHONY: clean pkg test
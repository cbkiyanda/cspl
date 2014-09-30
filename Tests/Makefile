cc = gcc 
checkmk = checkmk
install_name_tool = install_name_tool

headers = CSPL_Test.h
checkops = `pkg-config --libs check --cflags`
includedirs = -I../../CSPL/Stats
librarydirs = -L../ -lCSPL
libraries = -lCSPL
UNAME_S := $(shell uname -s)

all: Stats Array

Stats.c: Stats.check $(headers) Makefile
	$(checkmk) Stats.check > $@
Stats: Stats.c $(headers) Makefile
	$(cc) $(checkops) $(includedirs) $(librarydirs) $(libraries) Stats.c -o $@

Array.c: Array.check $(headers) Makefile
	$(checkmk) Array.check > $@
Array: Array.c $(headers) Makefile
	$(cc) $(checkops) $(includedirs) $(librarydirs) $(libraries) Array.c -o $@

clean:
	rm -f Stats.c Stats Array Array.c


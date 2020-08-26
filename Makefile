CFLAGS=-std=c11 -g -static

kc5: kc5.c

test: kc5
		./test.sh

clean:
		rm -f kc5 *.o tmp*

.PHONY: test clean

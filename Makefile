CFLAGS=-std=c11 -g

kc5: kc5.c
kc5-mac: kc5-mac.c

test: kc5
		./test.sh kc5

test-mac: kc5-mac
		./test.sh kc5-mac

clean:
		rm -f kc5 kc5-mac *.o tmp* a.out

.PHONY: test clean

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "illegal number of arguments\n");
        return 1;
    }

    char *p = argv[1];

    puts(".intel_syntax noprefix");
    puts(".globl _main");
    puts("_main:");

    while(*p) {
        if(isspace(*p)) {
            p++;
            continue;
        }
        if(*p == '+') {
            puts("  pop rdi");
            puts("  pop rax");
            puts("  add rax, rdi");
            puts("  push rax");
            p++;
            continue;
        }

        if(*p == '-') {
            puts("  pop rdi");
            puts("  pop rax");
            puts("  sub rax, rdi");
            puts("  push rax");
            p++;

            continue;
        }
        if(*p == '*') {
            puts("  pop rdi");
            puts("  pop rax");
            puts("  imul rax, rdi");
            puts("  push rax");
            p++;

            continue;
        }
        if(*p == '/') {
            puts("  pop rdi");
            puts("  pop rax");
            puts("  cqo");
            puts("  idiv rdi");
            puts("  push rax");
            p++;

            continue;
        }

        if(isdigit(*p)) {
            int n = 0;
            while(isdigit(*p)) {
                n = n * 10 + (*p - '0');
                p++;
            }
            printf("  push %d\n", n);
            continue;
        }

        fprintf(stderr, "unexpected character: '%c'\n", *p);
        return 1;
    }

    puts("  pop rax");
    puts("  ret");
    return 0;
}


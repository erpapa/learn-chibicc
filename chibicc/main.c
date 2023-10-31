//
//  main.c
//  chibicc
//
//  Created by apple on 2023/10/30.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        fprintf(stderr, "参数数量不正确\n");
        return 1;
    }

    char *p = (char *)argv[1];

    printf(".intel_syntax noprefix\n");
    printf(".globl _main\n");
    printf("_main:\n");
    printf("  mov rax, %ld\n", strtol(p, &p, 10));

    while (*p) {
        if (*p == '+') {
            p++;
            printf("  add rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        if (*p == '-') {
            p++;
            printf("  sub rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        fprintf(stderr, "意外字符: '%c'\n", *p);
        return 1;
    }

    printf("  ret\n");
    return 0;
}

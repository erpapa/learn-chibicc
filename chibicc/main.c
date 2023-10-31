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
        fprintf(stderr, "%s: invalid number of arguments\n", argv[0]);
        return 1;
    }

    // macOS中，汇编语言程序执行的起点是_main函数。
    // windows中，汇编语言程序执行的起点是_start函数。
    // linux中，汇编语言程序执行的起点是main函数。
    printf(".intel_syntax noprefix\n");
    printf(".global _main\n");
    printf("_main:\n");
    printf("  mov rax, %d\n", atoi(argv[1]));
    printf("  ret\n");
    return 0;
}

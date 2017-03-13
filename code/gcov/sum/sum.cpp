#ifndef SUM_FUNC_CPP
#define SUM_FUNC_CPP
#include <stdio.h>

unsigned int sum(unsigned int n) {
    unsigned int i, total = 0;

    for (i = 0; i < n; i++) {
        total += i;
    }

    if (total == 924) {
        printf("It is my lucky number.\n");
    }

    return total;
}

#endif

#include <stdio.h>
#include "sum.cpp"

int main(void) {
    unsigned int n = 10;
    printf("sum(%u)=%u", n, sum(n));

    return 0;
}

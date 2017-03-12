#ifndef SUM_FUNC_CPP
#define SUM_FUNC_CPP

unsigned int sum(unsigned int n) {
    unsigned int i, total = 0;

    for (i = 0; i < n; i++) {
        total += i;
    }

    return total;
}

#endif

#include <stdio.h>

#include "time_since.h"

#include "lcg.h"

#define ITERATIONS 100000

uint64_t state_history[ITERATIONS];
unsigned int history_index = 0;

static void print_history() {
    for (int i=0; i<ITERATIONS; ++i) {
        printf("%d, ", state_history[i]);
    }
    printf("\n");
}

static void test_lcg64_mod() {

    uint64_t lcg = 555;
    history_index = 0;

    cpu_time_start();
    for (int i=0; i<ITERATIONS; ++i) {
        lcg64_mod_next(&lcg);
        state_history[history_index++] = lcg;
    }
    unsigned long ns = cpu_time_get_delta_ns();
    printf("mod_time = %lu\n", ns);

#if 0
    printf("mod = [\n");
    print_history();
    printf("\n];\n");
#endif
}

static void test_lcg64_trunc() {
    uint64_t lcg = 555;
    history_index = 0;

    cpu_time_start();
    for (int i=0; i<ITERATIONS; ++i) {
        lcg64_trunc_next(&lcg);
        state_history[history_index++] = lcg;
    }
    unsigned long ns = cpu_time_get_delta_ns();
    printf("trunc_time = %lu\n", ns);

#if 0
    printf("trunc = [\n");
    print_history();
    printf("\n];\n");
#endif

}

int main() {

    test_lcg64_mod();
    test_lcg64_trunc();

    return 0;
}

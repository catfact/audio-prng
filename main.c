#include <stdio.h>

#include "time_since.h"

#include "lcg.h"

#define PRINT_HISTORY 0
#define ITERATIONS 100000

uint64_t state_history[ITERATIONS];
unsigned int history_index = 0;

static void print_history() {
    for (int i=0; i<ITERATIONS; ++i) {
        printf("%llu, ", state_history[i]);
    }
    printf("\n");
}

//----------------------------------------------------------------------
static void test_lcg64_mod() {

    uint64_t lcg = 555;
    history_index = 0;

    cpu_time_start();
    for (int i=0; i<ITERATIONS; ++i) {
        lcg64_mod_next(&lcg);
        state_history[history_index++] = lcg;
    }
    unsigned long ns = cpu_time_get_delta_ns();
    printf("mod_time = %lu;\n", ns);

#if PRINT_HISTORY
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
    printf("trunc_time = %lu;\n", ns);

#if PRINT_HISTORY
    printf("trunc = [\n");
    print_history();
    printf("\n];\n");
#endif
}


//----------------------------------------------------------------------
static void test_lcg32_mod() {
    uint32_t lcg = 555;
    history_index = 0;

    cpu_time_start();
    for (int i=0; i<ITERATIONS; ++i) {
        lcg32_mod_next(&lcg);
        state_history[history_index++] = lcg;
    }
    unsigned long ns = cpu_time_get_delta_ns();
    printf("mod_time_32 = %lu;\n", ns);

#if PRINT_HISTORY
    printf("mod_32 = [\n");
    print_history();
    printf("\n];\n");
#endif
}
static void test_lcg32_trunc() {
    uint32_t lcg = 555;
    history_index = 0;

    cpu_time_start();
    for (int i=0; i<ITERATIONS; ++i) {
        lcg32_trunc_next(&lcg);
        state_history[history_index++] = lcg;
    }
    unsigned long ns = cpu_time_get_delta_ns();
    printf("trunc_time_32 = %lu;\n", ns);

#if PRINT_HISTORY
    printf("trunc_32 = [\n");
    print_history();
    printf("\n];\n");
#endif
}

//----------------------------------------------------------------------
static void test_jmc() {
    struct lcg_jmc lcg;
    lcg.s1 = 0xdeadbeef;
    lcg.s2 = 0x23456789;
    lcg.s3 = 0x55555555;
    history_index = 0;

    uint32_t x;
    cpu_time_start();
    for (int i=0; i<ITERATIONS; ++i) {
        x = lcg_jmc_update(&lcg);
        state_history[history_index++] = x;
    }
    unsigned long ns = cpu_time_get_delta_ns();
    printf("jmc_time = %lu;\n", ns);

#if PRINT_HISTORY
    printf("jmc = [\n");
    print_history();
    printf("\n];\n");
#endif
}



int main() {

    test_lcg64_mod();
    test_lcg64_trunc();
    test_lcg32_mod();
    test_lcg32_trunc();
    test_jmc();

    return 0;
}

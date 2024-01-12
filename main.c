#include <stdio.h>

#include "time_since.h"

#include "lcg.h"

#define PRINT_HISTORY 0
#define PRINT_TIME 1
#define ITERATIONS 10000000

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
    double ns_per_iter = (double)ns / (double)ITERATIONS;
    printf("mod_time = %f;\n", ns_per_iter);

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
    double ns_per_iter = (double)ns / (double)ITERATIONS;

#if PRINT_TIME
    printf("trunc_time = %f;\n", ns_per_iter);
#endif

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
    double ns_per_iter = (double)ns / (double)ITERATIONS;
    printf("mod_time_32 = %f;\n", ns_per_iter);

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
    double ns_per_iter = (double)ns / (double)ITERATIONS;
    printf("trunc_time_32 = %f;\n", ns_per_iter);

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
    double ns_per_iter = (double)ns / (double)ITERATIONS;
    printf("jmc_time = %f;\n", ns_per_iter);

#if PRINT_HISTORY
    printf("jmc = [\n");
    print_history();
    printf("\n];\n");
#endif
}



int main() {

    // i think these are getting optimized to 32b registers anyway,
    // because the hardcoded operands ensure that 32b will not overflow
//    test_lcg64_mod();
//    test_lcg64_trunc();

    test_lcg32_mod();
    test_lcg32_trunc();
    test_jmc();

    return 0;
}

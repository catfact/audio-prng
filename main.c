#include <stdio.h>

#include "time_since.h"

#include "lcg.h"

#define ITERATIONS 100000

lcg_state_t state_history[ITERATIONS];
unsigned int history_index = 0;

static void print_history() {
    for (int i=0; i<ITERATIONS; ++i) {
        printf("%d, ", state_history[i]);
    }
    printf("\n");
}

static void test_lcg_mod() {

    struct lcg *lcg = lcg_create(555);
    history_index = 0;

    cpu_time_start();
    for (int i=0; i<ITERATIONS; ++i) {
        state_history[history_index++] = lcg_mod_next(lcg);
    }
    unsigned long ns = cpu_time_get_delta_ns();
    printf("mod_time = %lu\n", ns);

    lcg_destroy(lcg);

#if 0
    printf("mod = [\n");
    print_history();
    printf("\n];\n");
#endif
}

static void test_lcg_trunc() {
    struct lcg *lcg = lcg_create(555);
    history_index = 0;

    cpu_time_start();
    for (int i=0; i<ITERATIONS; ++i) {
        state_history[history_index++] = lcg_trunc_next(lcg);
    }
    unsigned long ns = cpu_time_get_delta_ns();
    printf("trunc_time = %lu\n", ns);
    lcg_destroy(lcg);

#if 0
    printf("trunc = [\n");
    print_history();
    printf("\n];\n");
#endif

}

int main() {

    test_lcg_mod();
    test_lcg_trunc();

    return 0;
}

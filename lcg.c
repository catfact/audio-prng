#include "lcg.h"

struct lcg* lcg_create(lcg_state_t seed) {
    struct lcg *lcg = malloc(sizeof(struct lcg));
    lcg->state = seed;
    return lcg;
}

void lcg_destroy(struct lcg *lcg) {
    free(lcg);
}

lcg_state_t lcg_mod_next(struct lcg *lcg) {
    lcg_state_t state = lcg->state;
    lcg_state_t next = (state * 0x41a7) % 0x7fffffff;
    lcg->state = next;
    return next;
}

lcg_state_t lcg_trunc_next(struct lcg *lcg) {
    lcg_state_t state = lcg->state;
    lcg_state_t next = ((lcg->state * 0x6255) + 0x3619) & 0x7fffffff;
    lcg->state = next;
    return next;
}
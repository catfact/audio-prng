#pragma once

#include <stdint.h>
#include <stdlib.h>

typedef uint64_t lcg_state_t;

//--- using modulo
struct lcg {
    lcg_state_t state;
};

extern struct lcg *lcg_create(lcg_state_t seed);
extern void lcg_destroy(struct lcg *lcg);

// --- multiplicative generator with modulo
extern lcg_state_t lcg_mod_next(struct lcg *state);

//--- mixed generator with trunctation
extern lcg_state_t lcg_trunc_next(struct lcg *state);
#pragma once

#include <stdint.h>
#include <stdlib.h>


// --- multiplicative generator with modulo
extern void lcg64_mod_next(uint64_t *state);

//--- mixed generator with trunctation
extern void lcg64_trunc_next(uint64_t *state);

// --- multiplicative generator with modulo
extern void lcg32_mod_next(uint32_t *state);

//--- mixed generator with trunctation
extern void lcg32_trunc_next(uint32_t *state);

// weird JMC generator
struct lcg_jmc {
    uint32_t s1;
    uint32_t s2;
    uint32_t s3;
};

extern uint32_t lcg_jmc_update(struct lcg_jmc *state);
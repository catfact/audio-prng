#include "lcg.h"

void lcg64_mod_next(uint64_t *state) {
    uint64_t next = (*state * 0x41a7) % 0x7fffffff;
    *state = next;
}

void lcg64_trunc_next(uint64_t* state) {
    uint64_t next = ((*state * 0x6255) + 0x3619) & 0x7fffffff;
    *state = next;
}

void lcg32_mod_next(uint32_t *state) {
    uint32_t next = (*state * 0x41a7) % 0x7fff;
    *state = next;
}

void lcg32_trunc_next(uint32_t *state) {
    uint32_t next = ((*state * 0x6255) + 0x3619) & 0x7fff;
    *state = next;
}

uint32_t lcg_jmc_update(struct lcg_jmc *state) {
uint32_t s1 = state->s1;
    uint32_t s2 = state->s2;
    uint32_t s3 = state->s3;

     s1 = ((s1 & (uint32_t)-2) << 12) ^ (((s1 << 13) ^ s1) >> 19);
     s2 = ((s2 & (uint32_t)-8) << 4) ^ (((s2 << 2) ^ s2) >> 25);
     s3 = ((s3 & (uint32_t)-16) << 17) ^ (((s3 << 3) ^ s3) >> 11);
     state->s1 = s1;
     state->s2 = s2;
     state->s3 = s3;
     return s1 ^ s2 ^ s3;
}
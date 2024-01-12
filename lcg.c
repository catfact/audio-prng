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
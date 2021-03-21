/*
 * easy_rng.
 * Simplifies sudo random number generation in C.
 * 
 * Copyright (C) 2021, Ty Gillespie. All rights reserved.
 * MIT License.
 * 
 * Usage:
 * This is a header-only library, contained all in one file. To use it, do the following in 1 .c file:
 * #define ER_IMPLEMENTATION
 * #include "easy_rng.h"
 * Then you can #include the header in any other part of the program.
 */

#ifndef EASY_RNG_H
#define EASY_RNG_H

#include<stdlib.h>
#include <time.h>

// Public API.

/*
 * er_init()
 * Seads the generator. If already initialized, returns 0 (false). Otherwise, returns 1 (true)
 */
int er_init();

/*
 * er_generate(int min, int max)
 * Returns a random number in the range provided. If not initialized, returns -1.
 */
int er_generate(int min, int max);

#endif // EASY_RNG_H

// Implenentation.

#ifdef ER_IMPLEMENTATION

int er_initialized = 0;

int er_init() {
    if (er_initialized == 1) {
        return 0;
    } else {
        srand(time(NULL));
        er_initialized = 1;
        return 1;
    }
}

int er_generate(int min, int max) {
    if (er_initialized == 0) {
        return -1;
    } else {
        int the_number = (rand() % (max - min + 1)) + min;
        return the_number;
    }
}

#endif // ER_IMPLEMENTATION

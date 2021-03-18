/*
 * Tests the easy_rng library.
 * 
 * Copyright (C) 2021, Ty Gillespie. All rights reserved.
 * MIT License.
 */

#define ER_IMPLEMENTATION
#include "easy_rng.h"
#include <stdio.h>

int main()
{
	er_init();
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", er_generate(1, 25));
	}
	return 0;
}

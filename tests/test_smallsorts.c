// 2 1 3 4 5 
// 2 3 1 4 5 
// 2 3 4 1 5 
// 2 3 4 5 1 
// 3 2 4 5 1 
// 3 4 2 5 1 
// 3 4 5 2 1 
// 3 4 5 1 2 
// 4 3 5 1 2 
// 4 5 3 1 2 
// 4 5 1 3 2 
// 4 5 1 2 3 
// 5 4 1 2 3 
// 5 1 4 2 3 
// 5 1 2 4 3 
// 5 1 2 3 4 
// 1 5 2 3 4 
// 1 2 5 3 4 
// 1 2 3 5 4 
// 1 2 3 4 5 

#include <criterion/criterion.h>
#include <stdio.h>

#include "push_swap.h"



Test(suite_5_args, base)
{
	cr_expect(1 == 0, "should be false.");
}


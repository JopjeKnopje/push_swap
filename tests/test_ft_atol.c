#include "test_push_swap.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


void assert_ft_atol(char *input, long expected)
{
	long output = ft_atol(input);
	cr_expect_eq(output, expected, "input: %s | output: %ld | expected output %ld\n", input, output, expected);
}

Test(ft_atol, args_1)
{
	assert_ft_atol("1", 1);
}

///////////////////////
// Limits max values //
///////////////////////
Test(ft_atol, args_2)
{
	assert_ft_atol("2147483647", 2147483647);
}

Test(ft_atol, args_3)
{
	assert_ft_atol("-2147483648", -2147483648);
}


Test(ft_atol, args_4)
{
	assert_ft_atol("9223372036854775807", 9223372036854775807);
}

Test(ft_atol, args_5)
{
	assert_ft_atol("-9223372036854775808", -9223372036854775808);
}

//////////////////////////
// Limits max values + 1//
//////////////////////////
Test(ft_atol, args_6)
{
	assert_ft_atol("-2147483649", -2147483649);
}

Test(ft_atol, args_7)
{
	assert_ft_atol("2147483648", 2147483648);
}

Test(ft_atol, args_8)
{
	assert_ft_atol("9223372036854775808", 9223372036854775808);
}

Test(ft_atol, args_9)
{
	assert_ft_atol("-9223372036854775809", -9223372036854775809);
}


Test(ft_atol, args_10)
{
	assert_ft_atol("+-1", 0);
}

Test(ft_atol, args_11)
{
	assert_ft_atol("+- 1", 0);
}

Test(ft_atol, args_12)
{
	assert_ft_atol("+-|-01", 0);
}

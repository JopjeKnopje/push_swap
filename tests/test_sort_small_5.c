/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_sort_small_5.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 11:33:05 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/07 11:49:50 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"



Test(sort_small_5, args_1)
{
	assert_sort_small("1 2 5 3 4", "1 2 3 4 5");
}

Test(sort_small_5, args_2)
{
	assert_sort_small("2 3 1 4 5", "1 2 3 4 5");
}

Test(sort_small_5, args_3)
{
	assert_sort_small("2 3 4 1 5", "1 2 3 4 5");
}

Test(sort_small_5, args_4)
{
	assert_sort_small("2 3 4 5 1", "1 2 3 4 5");
}

Test(sort_small_5, args_5)
{
	assert_sort_small("3 2 4 5 1", "1 2 3 4 5");
}

Test(sort_small_5, args_6)
{
	assert_sort_small("3 4 2 5 1", "1 2 3 4 5");
}

Test(sort_small_5, args_7)
{
	assert_sort_small("3 4 5 2 1", "1 2 3 4 5");
}

Test(sort_small_5, args_8)
{
	assert_sort_small("3 4 5 1 2", "1 2 3 4 5");
}

Test(sort_small_5, args_9)
{
	assert_sort_small("4 3 5 1 2", "1 2 3 4 5");
}

Test(sort_small_5, args_10)
{
	assert_sort_small("4 5 3 1 2", "1 2 3 4 5");
}

Test(sort_small_5, args_11)
{
	assert_sort_small("2 1 3 4 5", "1 2 3 4 5");
}

Test(sort_small_5, args_12)
{
	assert_sort_small("5 1 4 2 3", "1 2 3 4 5");
}

Test(sort_small_5, args_13)
{
	assert_sort_small("4 5 1 3 2", "1 2 3 4 5");
}

Test(sort_small_5, args_14)
{
	assert_sort_small("4 5 1 2 3", "1 2 3 4 5");
}

Test(sort_small_5, args_15)
{
	assert_sort_small("5 4 1 2 3", "1 2 3 4 5");
}

Test(sort_small_5, args_16)
{
	assert_sort_small("1 2 3 5 4", "1 2 3 4 5");
}

Test(sort_small_5, args_17)
{
	assert_sort_small("5 1 2 4 3", "1 2 3 4 5");
}

Test(sort_small_5, args_18)
{
	assert_sort_small("1 2 3 4 5", "1 2 3 4 5");
}

Test(sort_small_5, args_19)
{
	assert_sort_small("5 1 2 3 4", "1 2 3 4 5");
}

Test(sort_small_5, args_20)
{
	assert_sort_small("1 5 2 3 4", "1 2 3 4 5");
}

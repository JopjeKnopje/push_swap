/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_sort_small_3.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 11:38:41 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/07 11:46:15 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"




Test(sort_small_3, args_1)
{
	assert_sort_small("2 1 3", "1 2 3");
}

Test(sort_small_3, args_2)
{
	assert_sort_small("3 2 1", "1 2 3");
}

Test(sort_small_3, args_3)
{
	assert_sort_small("3 1 2", "1 2 3");
}

Test(sort_small_3, args_4)
{
	assert_sort_small("1 3 2", "1 2 3");
}

Test(sort_small_3, args_5)
{
	assert_sort_small("2 3 1", "1 2 3");
}

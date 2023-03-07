/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_sort_3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 11:38:41 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/07 11:38:42 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"


void assert_sort_3(char *s, char *expected)
{
	t_stack *stack = NULL;
	char **split = ft_split(s, ' ');

	int i = 0;
	while (split[i])
	{
		if (!stack)	
			stack = stack_new(ft_atol(split[i]));
		else
		 	stack_add_back(&stack, stack_new(ft_atol(split[i])));
		i++;
	}
	free_all(split, i);

	t_stack *stack_b = NULL;
	sort_small(&stack, &stack_b);

	char *output = stack_to_str(stack);
	stack_free(stack);

	cr_expect_str_eq(output, expected, "input: %s | output: %s | expected output %s\n", s, output, expected);
	free(output);
}



Test(sort_3, args_1)
{
	assert_sort_3("2 1 3", "1 2 3");
}

Test(sort_3, args_2)
{
	assert_sort_3("3 2 1", "1 2 3");
}

Test(sort_3, args_3)
{
	assert_sort_3("3 1 2", "1 2 3");
}

Test(sort_3, args_4)
{
	assert_sort_3("1 3 2", "1 2 3");
}

Test(sort_3, args_5)
{
	assert_sort_3("2 3 1", "1 2 3");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_push_swap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 11:32:55 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/07 11:47:58 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"


void assert_sort_small(char *s, char *expected)
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

char	**free_all(char **s_split, int i)
{
	while (i--)
		free(s_split[i]);
	free(s_split);
	return (NULL);
}

char *stack_to_str(t_stack *stack)
{
	int size = stack_size(stack);

	// sure we can calculate the buffersize but just hardcode it.
	char *s = ft_calloc(64, sizeof(char));
	char *s_start = s;

	while (stack)
	{
		if (s_start == s)
			sprintf(s, "%d", stack->nb);
		else
			sprintf(s, " %d", stack->nb);
		stack = stack->next;	
		s = s_start + ft_strlen(s_start);
	}
	return s_start;
}



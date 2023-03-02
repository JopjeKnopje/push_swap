
// TestSuite(smallsorts, .init=setup, .fini=cleanup);
//
// Test(smallsorts, args_1)
// {
// 	test_smallsort("push_swap 1 2 5 3 4");
// }

#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

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
		 	stack_add_front(&stack, stack_new(ft_atol(split[i])));
		i++;
	}
	free_all(split, i);

	t_stack *stack_b = NULL;
	sort_small(&stack, &stack_b);

	char *output = stack_to_str(stack);
	stack_free(stack);


	cr_expect_str_eq(output, expected);

	free(output);
}


Test(sort_3, args_1)
{
	assert_sort_3("3 2 1", "1 2 3");
}

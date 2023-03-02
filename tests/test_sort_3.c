
// TestSuite(smallsorts, .init=setup, .fini=cleanup);
//
// Test(smallsorts, args_1)
// {
// 	test_smallsort("push_swap 1 2 5 3 4");
// }

#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
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
	// sort_small(NULL, NULL);
	print_stacks(stack, NULL);
	stack_free(stack);
	free_all(split, i);

}

char *stack_to_str(t_stack *s)
{

	return NULL;
}


Test(sort_3, args_1)
{
	assert_sort_3("3 2 1", "1 2 3");
}

/**

  	TODO Read this
	https://github.com/Snaipe/Criterion/blob/bleeding/samples/parameterized.c




  */


#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/new_asserts.h>
#include <criterion/internal/test.h>
#include <criterion/logging.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
#include "push_swap.h"

t_stack *stack_sorted;
t_stack *head_a = NULL;
t_stack *head_b = NULL;

t_stack *create_stack_a(char *argv[], int argc);


static void free_all(char **s_split, int i)
{
	while (i--)
		free(s_split[i]);
	free(s_split);
}


static int stack_cmp(t_stack *head_a, t_stack *head_b)
{
	while (head_a && head_b) 
	{
		if (head_a->nb != head_b->nb)	
			return (0);
		head_b = head_b->next;
		head_a = head_a->next;
	}
	return (1);
}

int count_chr(char *s, char c)
{
	int i = 0;
	int count = 0;
	while (s[i]) 
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return count;
}

t_stack *test_smallsort(char *s)
{
	int size = count_chr(s, ' ') + 1;
	char **argv = ft_split(s, ' ');

	head_a = NULL;
	head_b = NULL;

	head_a = create_stack_a(argv, size);

	free_all(argv, size);
	cr_assert(head_a != 0, "head_a should not be zero.");

	smallsort(&head_a, &head_b);

	if (!stack_cmp(head_a, stack_sorted))
	{
		// print_stacks(head_a, stack_sorted);
		cr_fatal("Stack is not sorted.");
	}

	stack_free(head_a);
	stack_free(head_b);
	return head_a;
}


void setup(void)
{
	char *s = "push_swap 1 2 3 4 5";
	char **argv = ft_split(s, ' ');
	int size = count_chr(s, ' ') + 1;

	stack_sorted = create_stack_a(argv, size);
	free_all(argv, size);
}

void cleanup(void)
{
	stack_free(stack_sorted);
}


ReportHook(PRE_INIT)(struct criterion_test *test) 
{
    printf("testing %s in category %s\n", test->name, test->category);
}

ReportHook(POST_TEST)(struct criterion_test_stats *stats)
{
    // printf("Asserts: [%d passed, %d failed, %d total]\n",
    //         stats->passed_asserts, stats->failed_asserts, stats->passed_asserts + stats->failed_asserts);
}



TestSuite(smallsorts, .init=setup, .fini=cleanup);

Test(smallsorts, args_1)
{
	test_smallsort("push_swap 1 2 5 3 4");
}

Test(smallsorts, args_2)
{
	test_smallsort("push_swap 2 3 1 4 5");
}

Test(smallsorts, args_3)
{
	test_smallsort("push_swap 2 3 4 1 5");
}

Test(smallsorts, args_4)
{
	test_smallsort("push_swap 2 3 4 5 1");
}

Test(smallsorts, args_5)
{
	test_smallsort("push_swap 3 2 4 5 1");
}

Test(smallsorts, args_6)
{
	test_smallsort("push_swap 3 4 2 5 1");
}

Test(smallsorts, args_7)
{
	test_smallsort("push_swap 3 4 5 2 1");
}

Test(smallsorts, args_8)
{
	test_smallsort("push_swap 3 4 5 1 2");
}

Test(smallsorts, args_9)
{
	test_smallsort("push_swap 4 3 5 1 2");
}

Test(smallsorts, args_10)
{
	test_smallsort("push_swap 4 5 3 1 2");
}

Test(smallsorts, args_11)
{
	test_smallsort("push_swap 2 1 3 4 5");
}

Test(smallsorts, args_12)
{
	test_smallsort("push_swap 5 1 4 2 3");
}

Test(smallsorts, args_13)
{
	test_smallsort("push_swap 4 5 1 3 2");
}

Test(smallsorts, args_14)
{
	test_smallsort("push_swap 4 5 1 2 3");
}

Test(smallsorts, args_15)
{
	test_smallsort("push_swap 5 4 1 2 3");
}

Test(smallsorts, args_16)
{
	test_smallsort("push_swap 1 2 3 5 4");
}

Test(smallsorts, args_17)
{
	test_smallsort("push_swap 5 1 2 4 3");
}

Test(smallsorts, args_18)
{
	test_smallsort("push_swap 1 2 3 4 5");
}

Test(smallsorts, args_19)
{
	test_smallsort("push_swap 5 1 2 3 4");
}

Test(smallsorts, args_20)
{
	test_smallsort("push_swap 1 5 2 3 4");
}

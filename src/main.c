/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 09:21:42 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/08 19:16:29 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <time.h>

void do_sort(t_stack **stack_a, t_stack **stack_b)
{
	// t_stack *tmp = *stack_a;
	for (int i = 0; i <= 8; i++) 
	{
		operation_push(stack_a, stack_b);
	}
	operation_rotate(stack_b);
	// operation_swap(stack_a);
	// operation_push(stack_a, stack_b);
	// operation_push(stack_a, stack_b);
	// stack_add_back(stack_a, stack_new(42));
	// operation_swap(stack_a);
	// operation_push(stack_a, stack_b);
	// operation_push(stack_a, stack_b);
	// operation_push(stack_b, stack_a);
	// operation_push(stack_b, stack_a);
	// operation_push(stack_b, stack_a);
	// operation_push(stack_b, stack_a);
	// operation_swap(stack_a);
	// operation_swap(stack_b);
}

// !(!tmp_a && !tmp_b) == (tmp_a || tmp_b) WTF?
int main (int argc, char *argv[])
{
	srand(time(NULL));

	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	int i = 1;
	while (i <= 10)
	{
		stack_add_back(&stack_a, stack_new(i));
		i++;
	}

	print_stacks(stack_a, stack_b);
	do_sort(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);


	stack_free(&stack_a);
	stack_free(&stack_b);

	return 0;
}

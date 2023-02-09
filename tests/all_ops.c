/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 09:21:42 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/09 12:12:51 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

void do_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp = *stack_a;
	for (int i = 0; i <= 8; i++) 
	{
		operation_push(stack_a, stack_b);
	}
	operation_reverse_rotate(stack_b);
	operation_reverse_rotate(stack_b);
	operation_reverse_rotate(stack_b);
	operation_reverse_rotate(stack_b);
}

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

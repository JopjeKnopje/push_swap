/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 09:21:42 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/07 09:46:22 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void print_stacks(t_stack *head_a, t_stack *head_b)
{
	int len_a = stack_size(head_a);
	int len_b = stack_size(head_b);
	int len;
	t_stack *tmp_a = head_a;
	t_stack *tmp_b = head_b;

	if (len_a >= len_b)
		len = len_a;
	else
		len = len_b;

	while (len)
	{
		printf("%d\n", tmp_a->nb);


		if (!(tmp_a->next) && !(tmp_b->next))
		{
			printf("end of both list\n");
			break;
		}
		if (tmp_a->next)
			tmp_a = tmp_a->next;
		if (tmp_b->next)
			tmp_b = tmp_b->next;

		len--;
	}
	printf("=======================\n");
}

void do_sort(t_stack **stack_a, t_stack **stack_b)
{
	operation_push(stack_a, stack_b);
}

int main (int argc, char *argv[])
{
	t_stack *stack_a = stack_new(0);
	t_stack *stack_b = stack_new(0);
	int i = 1;
	while (i < 5)
	{
		stack_add_back(&stack_a, stack_new(i));
		i++;
	}
	
	print_stacks(stack_a);
	do_sort(&stack_a, &stack_b);
	print_stacks(stack_a);

	stack_free(&stack_a);
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 09:21:45 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/07 09:46:22 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_stacks(t_stack *head)
{
	t_stack *tmp = head;
	while (tmp)
	{
		printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}
	printf("=======================\n");
}

void do_sort(t_stack **head)
{
	t_stack *tmp = *head;
	while (tmp)
	{
		operation_swap(&(tmp->next));
		tmp = tmp->next;
	}
}

int main (int argc, char *argv[])
{
	t_stack *stack_head = stack_new(0);
	int i = 1;
	while (i < 5)
	{
		stack_add_back(&stack_head, stack_new(i));
		i++;
	}
	
	print_stack(stack_head);
	do_sort(&stack_head);
	print_stack(stack_head);

	stack_free(&stack_head);
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 09:21:45 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/06 09:31:21 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_stack(t_stack *head)
{
	t_stack *tmp = head;
	while (tmp)
	{
		printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}
	printf("=======================\n");
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
	
	operation_swap(&stack_head);

	print_stack(stack_head);
	stack_free(&stack_head);
	return 0;
}

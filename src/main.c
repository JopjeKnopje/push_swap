/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 09:21:42 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/08 10:01:08 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// yikes
void print_stacks(t_stack *head_a, t_stack *head_b)
{
	t_stack *tmp_a = head_a;
	t_stack *tmp_b = head_b;

	int len_a = stack_size(head_a);
	int len_b = stack_size(head_b);
	int len;
	int num_a;
	int num_b;

	if (head_a)
		num_a = head_a->nb;
	else
	 	num_a = -1;
	if (head_b)
		num_b = head_b->nb;
	else
	 	num_b = -1;


	if (len_a >= len_b)
		len = len_a;
	else
		len = len_b;

	while (len)
	{
		if (num_a == -1)
			printf("             ");
		else
			printf("stack_a %4d ", num_a);

		if (num_b == -1)
			printf("            \n");
		else
			printf("| stack_b %4d\n", num_b);

		if ((!(tmp_a) || !(tmp_b)) || !(tmp_a->next) && !(tmp_b->next))
			break;

		if (tmp_a->next)
			tmp_a = tmp_a->next, num_a = tmp_a->nb;
		else
			num_a = -1;
		if (tmp_b->next)
			tmp_b = tmp_b->next, num_b = tmp_b->nb;
		else
			num_b = -1;
		len--;
	}
	printf("=============================\n");
}


void do_sort(t_stack **stack_a, t_stack **stack_b)
{
	for (int i = 0; i <= 10; i++) {
	
		operation_push(stack_a, stack_b);
	}
}

int main (int argc, char *argv[])
{
	srand(time(NULL));

	t_stack *stack_a = stack_new(0);
	t_stack *stack_b = stack_new(0);
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

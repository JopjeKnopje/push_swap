/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 14:24:01 by jboeve        #+#    #+#                 */
/*   Updated: 2023/02/08 18:56:18 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_stack *head_a, t_stack *head_b)
{
	t_stack *tmp_a = head_a;
	t_stack *tmp_b = head_b;

	int stack_a_len = stack_size(head_a);
	int stack_b_len = stack_size(head_b);

	while (tmp_a || tmp_b)
	{
		if (tmp_a)
			printf("stack_a %4d\t", tmp_a->nb);
		else 
			printf("\t\t");
		if (tmp_b)
			printf("| stack_b %4d\n", tmp_b->nb);
		else
			printf("\n");
		
		if (tmp_a && tmp_a->next)
			tmp_a = tmp_a->next;
		else
		 	tmp_a = NULL;
		if (tmp_b && tmp_b->next)
			tmp_b = tmp_b->next;
		else
		 	tmp_b = NULL;
	}
	printf("==============================\n");
}

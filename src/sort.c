/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 19:53:17 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/24 21:42:11 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void bubblesort(t_stack *head) 
{ 
	t_stack *tmp;
	int swapped = 1;

	while (swapped)
	{
		swapped = 0;
		tmp = head;

		while (tmp->next)
		{
			if (tmp->nb > tmp->next->nb)
			{
				int x = tmp->nb;
				tmp->nb = tmp->next->nb;
				tmp->next->nb = x;
				swapped = 1;
			}
			tmp = tmp->next;
		}
	}
} 

static void apply_offset(t_stack *head_a, t_stack *head_sorted)
{
	t_stack *tmp = head_a;

	int index = 0;
	while (head_sorted) 
	{
		tmp = head_a;
		index = 0;
		while (tmp)
		{
			if (tmp->nb == head_sorted->nb)
				tmp->nb = index;
			tmp = tmp->next;	
			index++;
		}
		head_sorted = head_sorted->next;	
	}
}


void radixsort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *stack_a_copy;

	stack_a_copy = stack_dup(*stack_a);

	bubblesort(stack_a_copy);
	apply_offset(*stack_a, stack_a_copy);
	stack_free(stack_a_copy);

	int shift;
	int size_a;
	int i;

	shift = 0;
	while (!stack_is_sorted(*stack_a)) 
	{
		i = 0;
		size_a = stack_size(*stack_a);
		while (i < size_a)
		{
			if ((*stack_a)->nb >> shift & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			i++;
		}
		while ((*stack_b)) 
			pa(stack_a, stack_b);
		shift++;
	}
}

void 	smallsort(t_stack *stack_a, t_stack *stack_b)
{
	
}

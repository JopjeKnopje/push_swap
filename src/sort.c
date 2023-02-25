/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 19:53:17 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/25 17:10:57 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

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
	// TODO Use different kind of array.
	int *isset = ft_calloc(stack_size(head_a), sizeof(int));
	if (!isset)
		return ;

	int index = 0;
	int j;

	while (head_sorted) 
	{
		j = 0;
		tmp = head_a;
		while (tmp)
		{
			if (tmp->nb == head_sorted->nb && !isset[j])
			{
				tmp->nb = index;
				isset[j] = 1;
			}
			tmp = tmp->next;
			j++;
		}
		head_sorted = head_sorted->next;	
		index++;
	}
	free(isset);
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


void 	smallsort(t_stack **stack_a, t_stack **stack_b)
{
	// TODO Implement.
}

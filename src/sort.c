/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 19:53:17 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/07 15:37:43 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>
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


void sort_radix(t_stack **stack_a, t_stack **stack_b)
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

// TODO remove if statements for each case.
static void 	sort_3(t_stack **stack)
{
	int nb[3] = {
		(*stack)->nb,
		(*stack)->next->nb,
		(*stack)->next->next->nb
	};

	if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] < nb[2])
	{
		sa(stack);
	}
	else if (nb[0] > nb[1] && nb[1] > nb[2] && nb[0] > nb[2])
	{
		sa(stack);
		rra(stack);
	}
	else if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] > nb[2])
	{
		ra(stack);
	}
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] < nb[2])
	{
		sa(stack);
		ra(stack);
	}
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] > nb[2])
	{
		rra(stack);
	}
}


int find_rotates(t_stack *stack)
{
	int i = 0;
	t_stack *max = stack_max(stack);

	while (stack != max)
	{
		i++;
		stack = stack->next;
	}

	return i;
}

static void 	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int size = stack_size(*stack_a);
	int r_count = find_rotates(*stack_a);
	int i;
	int j = 0;
	while (i < size - 3)
	{
		r_count = find_rotates(*stack_a);
		j = 0;
		while (j < r_count) 
		{
			j++;
			ra(stack_a);
		}
		pb(stack_a, stack_b);
		i++;
	}
	sort_3(stack_a);
	if (!stack_is_sorted(*stack_b) && stack_size(*stack_b) <= 2)
		sb(stack_b);
	else if (!stack_is_sorted(*stack_b))
		sort_3(stack_b);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}

void 	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	// TODO When sorting more than 3 values push the remaining to stack_b to sort it there.
	int size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	// if (size == 3)
	// 	sort_3(stack_a, stack_b);
	// if(size == 5)
	// 	sort_5(stack_a, stack_b);
	sort_5(stack_a, stack_b);
	// print_stacks(*stack_a, *stack_b);
}

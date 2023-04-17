/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 16:52:11 by joppe         #+#    #+#                 */
/*   Updated: 2023/04/17 11:43:32 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	bubblesort(t_stack **head)
{
	t_stack	**head_tmp;
	int		swapped;

	if (!head)
		return (0);
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		head_tmp = head;
		while ((*head_tmp)->next)
		{
			if ((*head_tmp)->nb > (*head_tmp)->next->nb)
			{
				if (!operation_swap(head_tmp))
					return (0);
				swapped = 1;
			}
			head_tmp = &(*head_tmp)->next;
		}
	}
	return (1);
}

static void	inner_loop(t_stack *head, t_stack *tmp, int *isset, int index)
{
	int	j;

	j = 0;
	while (head)
	{
		if (head->nb == tmp->nb && !isset[j])
		{
			head->nb = index;
			isset[j] = 1;
		}
		head = head->next;
		j++;
	}
}

static	int	apply_offset(t_stack *head_a, t_stack *head_sorted)
{
	t_stack	*tmp;
	int		*is_set;
	int		index;

	if (!head_a || !head_sorted)
		return (0);
	is_set = ft_calloc(stack_size(head_a), sizeof(int));
	if (!is_set)
		return (0);
	tmp = head_sorted;
	index = 0;
	while (tmp)
	{
		inner_loop(head_a, tmp, is_set, index);
		tmp = tmp->next;
		index++;
	}
	free(is_set);
	return (1);
}

static	int	do_radix(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		err;
	int		shift;
	int		size;

	shift = 0;
	while (!stack_is_sorted(*stack_a))
	{
		i = 0;
		size = stack_size(*stack_a);
		while (i++ < size)
		{
			if ((*stack_a)->nb >> shift & 1)
				err = ra(stack_a);
			else
				err = pb(stack_a, stack_b);
			if (!err)
				return (0);
		}
		while ((*stack_b))
			if (!pa(stack_a, stack_b))
				return (0);
		shift++;
	}
	return (1);
}

int	sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_a_copy;

	stack_a_copy = stack_dup(*stack_a);
	if (!stack_a_copy)
		return (0);
	if (!bubblesort(&stack_a_copy))
	{
		stack_free(stack_a_copy);
		return (0);
	}
	if (!apply_offset(*stack_a, stack_a_copy))
	{
		stack_free(stack_a_copy);
		return (0);
	}
	stack_free(stack_a_copy);
	return (do_radix(stack_a, stack_b));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 16:52:11 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/15 20:51:35 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Maybe move node instead of value.
// static	void	bubblesort(t_stack *head)
void	bubblesort(t_stack *head)
{
	t_stack	*head_tmp;
	int		swapped;
	int		tmp_val;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		head_tmp = head;
		while (head_tmp->next)
		{
			if (head_tmp->nb > head_tmp->next->nb)
			{
				tmp_val = head_tmp->nb;
				head_tmp->nb = head_tmp->next->nb;
				head_tmp->next->nb = tmp_val;
				swapped = 1;
			}
			head_tmp = head_tmp->next;
		}
	}
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

// static	void	apply_offset(t_stack *head_a, t_stack *head_sorted)
int	apply_offset(t_stack *head_a, t_stack *head_sorted)
{
	t_stack	*tmp;
	int		*isset;
	int		index;
	int		j;

	isset = ft_calloc(stack_size(head_a), sizeof(int));
	if (!isset)
		return (1);
	index = 0;
	while (head_sorted)
	{
		inner_loop(head_a, head_sorted, isset, index);
		head_sorted = head_sorted->next;
		index++;
	}
	free(isset);
	stack_free(head_sorted);
	return (0);
}

void	sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_a_copy;
	int		shift;
	int		size_a;
	int		i;

	stack_a_copy = stack_dup(*stack_a);
	bubblesort(stack_a_copy);
	apply_offset(*stack_a, stack_a_copy);
	stack_free(stack_a_copy);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 19:53:17 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/22 21:41:33 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void bubblesort(t_stack *head) 
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

void apply_offset(t_stack **head_a, t_stack *head_sorted)
{
	t_stack *tmp_input = *head_a;
	t_stack *tmp_sorted = head_sorted;
	t_stack *tmp_modified = NULL;

	int index = 0;
	while (tmp_input) 
	{
		tmp_sorted = head_sorted;
		index = 0;
		while (tmp_sorted)
		{
			if (tmp_sorted->nb == tmp_input->nb)
			{
				// TODO Figure out this part
				// tmp_input->nb = index;
				if (!tmp_modified)
					tmp_modified = stack_new(index);
				else
					stack_add_back(&tmp_modified, stack_new(index));
			}
			tmp_sorted = tmp_sorted->next;	
			index++;
		}
		tmp_input = tmp_input->next;	
	}
	stack_free(head_a);
	*head_a = tmp_modified;
}

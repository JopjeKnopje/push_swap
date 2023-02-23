/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 19:53:17 by joppe         #+#    #+#                 */
/*   Updated: 2023/02/23 14:31:00 by joppe         ########   odam.nl         */
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
	int i = 0;
	while (tmp_sorted) 
	{
		tmp_input = *head_a;
		index = 0;
		while (tmp_input)
		{
			if (tmp_input->nb == tmp_sorted->nb)
			{
				// TODO Figure out this part
				print_stacks(*head_a, head_sorted);
				tmp_input->nb = index;
				// if (!tmp_modified)
				// 	tmp_modified = stack_new(index);
				// else
				// 	stack_add_back(&tmp_modified, stack_new(index));
			}
			tmp_input = tmp_input->next;	
			index++;
		}
		tmp_sorted = tmp_sorted->next;	
	}
	// stack_free(head_a);
	// *head_a = tmp_modified;
}

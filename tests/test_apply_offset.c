/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_apply_offset.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 15:21:57 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/10 17:42:15 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void	bubblesort(t_stack *head);
void	apply_offset(t_stack *head_a, t_stack *head_sorted);

Test(apply_offset, args_1)
{
	t_stack *head = stack_new(10);
	for (int i = 0; i < 10; i++) 
	{
		stack_add_back(&head, stack_new(rand() % 50));
	}
	t_stack *head_copy = stack_dup(head);

	bubblesort(head_copy);
	print_stacks(head, head_copy);

	apply_offset(head, head_copy);

	print_stacks(head, head_copy);

	stack_free(head);
	stack_free(head_copy);
}


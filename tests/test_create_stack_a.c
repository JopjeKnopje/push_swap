/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_create_stack_a.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 23:09:45 by joppe         #+#    #+#                 */
/*   Updated: 2023/03/13 23:32:12 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test_push_swap.h"


t_stack	*create_stack_a(char *argv[], int argc);

Test(test_create_stack_a, args_1)
{
	char *argv[] = {
		"1",
		"2",
		"3",
		NULL
	};

	t_stack *expected_head = stack_new(1);
	stack_add_back(&expected_head, stack_new(2));
	stack_add_back(&expected_head, stack_new(3));

	t_stack *head = create_stack_a(argv, 3);

	print_stacks(head, expected_head);

	stack_free(head);
	stack_free(expected_head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/04/11 11:06:02 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static	int	push_swap(int argc, char *argv[])
{
	t_stack	*head_a;

	argv = parse_args(argv);
	if (argv)
	{
		head_a = create_stack_a(argv, str_arr_len(argv));
		if (!head_a)
		{
			free_split(argv);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		if (stack_is_sorted(head_a))
		{
			stack_free(head_a);
			return (free_split(argv));
		}
		if (!do_sort(&head_a))
			ft_putstr_fd("Malloc error\n", STDERR_FILENO);
		stack_free(head_a);
		free_split(argv);
	}
	// TODO: Add argc < 2
	if (!argv && argc > 1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_SUCCESS);
}


#ifndef BUILD_TESTER

int	main(int argc, char *argv[])
{
	// argv = parse_args(argv);
	// t_stack *head = create_stack_a(argv, str_arr_len(argv));
	// free_split(argv);
	// stack_free(head);
	return (push_swap(argc, argv));
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/04/10 11:18:31 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!argv && argc > 1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_SUCCESS);
}

#ifndef BUILD_TESTER

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (EXIT_SUCCESS);
	return (push_swap(argc, argv));
}

#endif

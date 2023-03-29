/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/29 17:02:20 by jboeve        ########   odam.nl         */
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
		if (is_stack_sorted(head_a))
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

void	check_leaks(void)
{
	system("Leaks push_swap");
}

#ifndef BUILD_TESTER

int	main(int argc, char *argv[])
{
	// atexit(check_leaks);
	return (push_swap(argc, argv));
}

#endif

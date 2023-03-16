/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/16 17:32:56 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char *argv[])
{
	t_stack	*head_a;
	int		argv_len;

	argv = parse_args(argv);
	if (argv)
	{
		argv_len = str_arr_len(argv);
		head_a = create_stack_a(argv, argv_len);
		if (!head_a)
		{
			free_split(argv);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		if (stack_is_sorted(head_a))
			return (0);
		if(!do_sort(&head_a))
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
	return (push_swap(argc, argv));
}

#endif

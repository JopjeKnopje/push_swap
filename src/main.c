/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/14 00:17:55 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char *argv[])
{
	t_stack	*head_a;

	if (argc <= 1)
		return (0);
	argv = parse_args(argv);
	if (argc > 1 && argv)
	{
		head_a = create_stack_a(argv, argc);
		if (head_a && stack_is_sorted(head_a))
		{
			stack_free(head_a);
			head_a = NULL;
		}
		if (!head_a)
		{
			printf("Error!\n");
			return (0);
		}
		do_sort(&head_a);
		stack_free(head_a);
		free_split(argv);
	}
	else
		printf("Error!\n");
	return (0);
}

#ifndef BUILD_TESTER

int	main(int argc, char *argv[])
{
	// return (push_swap(argc, argv));

	char **args = parse_args(argv);
	if (!args)
	{
		printf("parse_args is null\n");
		return 0;
	}
	int i = 0;
	while (args[i])
	{
		printf("[%s]\n", args[i]);
		i++;
	}


	if (args)
		free_split(args);
}

#endif

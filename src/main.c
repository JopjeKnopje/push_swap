/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/08 17:05:23 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char *argv[])
{
	t_stack	*head_a;
	t_stack	*head_b;

	if (argc <= 1)
		return (0);
	argv = parse_args(argv);
	if (argc > 1 && argv)
	{
		head_a = create_stack_a(argv, argc - 1);
		if (stack_is_sorted(head_a))
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
	}
	else
		printf("Error!\n");
	return (0);
}

#ifndef BUILD_TESTER

int	main(int argc, char *argv[])
{
	return (push_swap(argc, argv));
}

#endif


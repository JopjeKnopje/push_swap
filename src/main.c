/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/16 13:18:20 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push_swap1(int argc, char *argv[])
{
	t_stack	*head_a;

	if (argc <= 1)
		return (0);
	argv = parse_args(argv);
	if (argv && str_arr_len(argv) <= 1)
	{
		free_split(argv);
		return 0;
	}
	if (argv)
	{
		head_a = create_stack_a(argv, str_arr_len(argv));
		if (head_a && stack_is_sorted(head_a))
		{
			stack_free(head_a);
			free_split(argv);
			head_a = NULL;
			return 0;
		}
		if (!head_a)
		{
			printf("Error!\n");
			free_split(argv);
			return (0);
		}
		do_sort(&head_a);
		stack_free(head_a);
	}
	else
		printf("Error!\n");
	if (argv)
		free_split(argv);
	return (0);
}

#ifndef BUILD_TESTER

void	print_split(char **s)
{
	int i = 0;
	printf("print_split\n");
	while (s[i]) 
	{
		printf("[%s]\n", s[i]);
		i++;
	}
}


int	push_swap(int argc, char *argv[])
{
	t_stack *head_a;
	int 	argv_len;

	argv = parse_args(argv);
	if (argv)
	{
		argv_len = str_arr_len(argv);
		head_a = create_stack_a(argv, argv_len);
		// print_stacks(head_a, NULL);
		if (!head_a)
		{
			free_split(argv);
			printf("Error!\n");
			return 0;
		}
		do_sort(&head_a);
		stack_free(head_a);
		free_split(argv);
	}
	if (!argv)
		printf("Error!\n");
	return 0;
}


int	main(int argc, char *argv[])
{
	return (push_swap(argc, argv));
}

#endif

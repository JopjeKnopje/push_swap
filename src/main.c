/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/14 20:56:19 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push_swap(int argc, char *argv[])
{
	t_stack	*head_a;

	if (argc <= 1)
		return (0);
	argv = parse_args(argv);
	if (argv && ptr_arr_len(argv) > 1)
	{
		head_a = create_stack_a(argv, ptr_arr_len(argv));
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
	}
	else
		printf("Error!\n");
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


int	main(int argc, char *argv[])
{
	return (push_swap(argc, argv));

	// char **args = parse_args(argv);
	// if (!args)
	// {
	// 	printf("args = null\n");
	// 	return 0;
	// }
	// int i = 0;
	// 
	// while (args[i]) 
	// {
	// 	printf("i %d | s %s\n", i, args[i]);	
	// 	i++;
	// }
	// printf("i: %d\n", i);


	// char **args = parse_args(argv);
	// if (!args)
	// {
	// 	printf("parse_args is null\n");
	// 	return 0;
	// }
	// int i = 0;
	// while (args[i])
	// {
	// 	printf("[%s]\n", args[i]);
	// 	i++;
	// }
	//
	// t_stack *head = create_stack_a(args, argc);
	//
	//
	// if (args)
	// 	free_split(args);
}

#endif

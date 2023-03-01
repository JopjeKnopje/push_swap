/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/03/01 16:09:35 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>


t_stack *create_stack_a(char *argv[], int argc)
{
	t_stack *head; 

	int i = 1;
	head = 0;

	while (argc - 1)
	{
		long num = atol(argv[argc - 1]);
		if (num > INT_MAX || num < INT_MIN) 
		{
			stack_free(head);
			return 0;
		}
		if (!head)
			head = stack_new(num);
		else
			stack_add_front(&head, stack_new(num));
		argc--;
	}
	return (head);
}

void exit_program(t_stack *head_a, t_stack *head_b)
{
	stack_free(head_a);
	stack_free(head_b);
	exit(EXIT_SUCCESS);
}

void do_sort(t_stack **head_a, t_stack **head_b)
{
	int size = stack_size(*head_a);

	if (size <= 5)
		sort_small(head_a, head_b);
	else
		sort_radix(head_a, head_b);

}

// TODO Have head_b in the actual sorting function
int push_swap(int argc, char *argv[])
{
	t_stack *head_a = NULL;
	t_stack *head_b = NULL;

	if (argc <= 1)
		return (0);
	if (argc > 1 && parse_args(argv))
	{
		head_a = create_stack_a(argv, argc);
		if (stack_is_sorted(head_a))
		{
			stack_free(head_a);
			head_a = NULL;
		}
		if (!head_a)
		{
			printf("Error!\n");
			return 0;
		}
		do_sort(&head_a, &head_b);
		stack_free(head_a);
		stack_free(head_b);
	}
	else
		printf("Error!\n");
	return (0);
}


#ifndef BUILD_TESTER
int main(int argc, char *argv[])
{
	push_swap(argc, argv);
	return EXIT_SUCCESS;
}
#endif

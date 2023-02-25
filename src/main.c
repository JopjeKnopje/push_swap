/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/02/25 16:29:36 by joppe         ########   odam.nl         */
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


// TODO Have head_b in the actual sorting function
int main(int argc, char *argv[])
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
			printf("stack is already sorted\n");
		}
		if (!head_a)
		{
			printf("Error!\n");
			return 0;
		}
		// print_stacks(head_a, head_b);
		radixsort(&head_a, &head_b);
	  	// print_stacks(head_a, head_b);


		stack_free(head_a);
		stack_free(head_b);
	}
	else
		printf("Error!\n");

	return (0);
}

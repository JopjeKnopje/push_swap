/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/02/09 13:30:00 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>


// TODO Add to libft
int is_num_str(char *s)
{
	int i = 0;
	int counter = 0;
	while (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i]) 
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int parse_args(char *argv[])
{
	int i = 1;

	while (argv[i]) 
	{
		if (!is_num_str(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
      
t_stack *create_stack_a(char *argv[], int argc)
{
	t_stack *head; 

	int i = 1;
	head = 0;

	// if argv is 0 we get error?
	while (argv[i])
	{
		long num = atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN) 
		{
			stack_free(&head);
			return 0;
		}
		if (!head)
			head = stack_new(num);
		else
			// TODO Instead of stack_add_back reverse iterate over the argv array.
			stack_add_back(&head, stack_new(num));
		i++;
	}
	return (head);
}

// testing to see if the stack operations work.
void do_sort(t_stack **stack_a, t_stack **stack_b)
{
	operation_push(stack_a, stack_b);
	operation_push(stack_a, stack_b);
	operation_push(stack_a, stack_b);
	operation_reverse_rotate(stack_b);
}


int main(int argc, char *argv[])
{
	t_stack *head_a = NULL;
	t_stack *head_b = NULL;
	if (argc > 1 && parse_args(argv))
	{
		// add to list
		head_a = create_stack_a(argv, argc);
		if (!head_a)
		{
			printf("Error!\n");
			return 0;
		}

		print_stacks(head_a, head_b);
		do_sort(&head_a, &head_b);
		print_stacks(head_a, head_b);

		stack_free(&head_a);
		stack_free(&head_b);
	}
	else
		printf("Error!\n");

	return (0);
}

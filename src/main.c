/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/02/22 15:43:30 by joppe         ########   odam.nl         */
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
			stack_free(&head);
			return 0;
		}
		// TODO instead of adding INT_MAX find the smallest number and add that to all elements.
		unsigned int scaled_num = num + INT_MAX;
		if (!head)
			head = stack_new(scaled_num);
		else
			stack_add_front(&head, stack_new(scaled_num));
		argc--;
	}
	return (head);
}



int is_sorted(t_stack *stack)
{
	t_stack *tmp = stack;
	while (tmp)
	{
		if (!(tmp->next))
			break;
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void push_largest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp = *stack_a;
	int largest = (*stack_a)->nb;

	while (tmp)
	{
		if (tmp->nb > largest)	
		{
			largest = tmp->nb;
		}
		tmp = tmp->next;
	}

	// TODO Check wheter to use ra or rra
	while ((*stack_a)->nb < largest)
		ra(stack_a);
	pb(stack_a, stack_b);
}

void do_sort(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int shift = 0;
	int size = stack_size(*stack_a);

	while (shift < 10) 
	{
		size = stack_size(*stack_a);
		while (size) 
		{
			if ((*stack_a)->nb >> shift & 0)
			{
				printf("pb %d\n", (*stack_a)->nb - INT_MAX);
				pb(stack_a, stack_b);
			}
			else
			{
				ra(stack_a);
			}
			size--;
		}
		shift++;
	
	}
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

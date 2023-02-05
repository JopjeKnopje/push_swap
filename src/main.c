/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/02/05 20:08:01 by joppe         ########   odam.nl         */
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
      
t_stack *create_stack_a(char *argv[])
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
			stack_add_front(&head, stack_new(num));
		i++;
	}
	return (head);
}

void print_node(t_stack *head)
{
	t_stack *tmp = head;
	while (tmp)
	{
		printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}
}


int main(int argc, char *argv[])
{
	t_stack *head_a;
	if (argc > 1 && parse_args(argv))
	{
		// add to list
		head_a = create_stack_a(argv);
		if (!head_a)
		{
			printf("input error\n");
			return 0;
		}
		
		print_node(head_a);
		stack_free(&head_a);
	}
	else
		printf("error!\n");

	return (0);
}

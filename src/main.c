/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboeve <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:06:53 by jboeve        #+#    #+#                 */
/*   Updated: 2023/02/02 16:20:03 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


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
      
t_node *create_stack_a(char *argv[])
{
	// t_node *head = stack_new(ft_atoi(argv[1]));
	t_node *head;
	long num = atol(argv[1]);

	int i = 2;
	while (argv[i])
	{
		num = atol(argv[1]);
		stack_add_front(&head, stack_new(num));
		// stack_add_back(&head, stack_new(num));
		i++;
	}
	return (head);
}

void print_node(t_node *head)
{
	t_node *tmp = head;
	while (tmp)
	{

		printf("%d\n", tmp->nb);

		if (!tmp->next)
			break ;

		tmp = tmp->next;
	}
}


int main (int argc, char *argv[])
{
	t_node *head_a;
	if (argc > 1 && parse_args(argv))
	{
		// add to list
		head_a = create_stack_a(argv);
		
		print_node(head_a);
		stack_free(&head_a);
	}
	else
		printf("Error!\n");

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:22:55 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/15 12:22:55 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../push_swap.h"
#include <stdio.h>

void	exec_command(char *line, t_node *stack_a, t_node *stack_b)
{
	if (ft_strcmp(line, "sa"))
		sa_checker(stack_a);
	else if (ft_strcmp(line, "sb"))
		sb_checker(stack_b);
	else if (ft_strcmp(line, "ss"))
		ss_checker(stack_a, stack_b);
	else if (ft_strcmp(line, "pa"))
		pa_checker(stack_a, stack_b);
	else if (ft_strcmp(line, "pb"))
		pb_checker(stack_a, stack_b);
	else if (ft_strcmp(line, "ra"))
		ra_checker(stack_a);
	else if (ft_strcmp(line, "rb"))
		rb_checker(stack_b);
	else if (ft_strcmp(line, "rr"))
		rr_checker(stack_a, stack_b);
	else if (ft_strcmp(line, "rra"))
		rra_checker(stack_a);
	else if (ft_strcmp(line, "rrb"))
		rrb_checker(stack_b);
	else if (ft_strcmp(line, "rrr"))
		rrr_checker(stack_a, stack_b);
	else
		printf("error");
}

void	ordered_checker(t_node *stack_a, t_node *stack_b)
{
	stack_a = stack_a->next;
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
		{
			printf("KO\n");
			return ;
		}
		stack_a = stack_a->next;
	}
	if (stack_length(stack_b) == 0)
		printf("OK\n");
	else
		printf("KO\n");
}

void	populate_checker(t_node *stack, int size, char *argv[])
{
	int	i;

	i = 0;
	stack->next = (t_node *)malloc(sizeof(t_node));
	stack->next->previous = stack;
	stack->previous = NULL;
	stack = stack->next;
	while (i < size - 2)
	{
		stack->next = (t_node *)malloc(sizeof(t_node));
		stack->next->previous = stack;
		stack->value = atoi(argv[i + 1]);
		stack = stack->next;
		i++;
	}
	stack->value = atoi(argv[i + 1]);
	stack->next = NULL;
}

void	print_stack(t_node *stack_a, t_node *stack_b)
{
	stack_a = stack_a->next;
	while (stack_a->next)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("%d\n", stack_a->value);
	printf("&&\n");
	if (stack_b->next)
	{
		stack_b = stack_b->next;
		while (stack_b->next)
		{
			printf("%d\n", stack_b->value);
			stack_b = stack_b->next;
		}
		printf("%d\n", stack_b->value);
	}
	printf("--\n");
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*line;
	int		i;

	i = 1;
	stack_a = init_stack();
	stack_b = init_stack();
	populate_checker(stack_a, argc, argv);
	while (i)
	{
		i = get_next_line(0, &line);
		if (!i)
		{
			free(line);
			break ;
		}
		exec_command(line, stack_a, stack_b);
		free(line);
	}
	ordered_checker(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

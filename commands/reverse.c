/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:03:11 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/09 15:03:12 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rra(s_node *stack)
{
	s_node	*start;
	s_node	*last;
	int		counter;

	if (more_than_one(stack))
		return ;
	counter = 0;
	start = stack;
	while (stack->next)
	{
		stack = stack->next;
		counter++;
	}
	last = stack;
	stack = start;
	if (counter == 2)
	{
		sa(stack);
		return ;
	}
	last->next = stack->next;
	last->previous->next = NULL;
	stack->next = last;
	last->previous = stack;
	last->next->previous = last;
	print_command("rra");
}

void	rrb(s_node *stack)
{
	s_node	*start;
	s_node	*last;
	int		counter;

	if (more_than_one(stack))
		return ;
	counter = 0;
	start = stack;
	while (stack->next)
	{
		stack = stack->next;
		counter++;
	}
	last = stack;
	stack = start;
	if (counter == 2)
	{
		sb(stack);
		return ;
	}
	last->next = stack->next;
	last->previous->next = NULL;
	stack->next = last;
	last->previous = stack;
	last->next->previous = last;
	print_command("rrb");
}

void	rrr(s_node *stack_a, s_node *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

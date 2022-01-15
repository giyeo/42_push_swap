/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:03:11 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/15 00:32:47 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra_checker(t_node *stack)
{
	t_node	*start;
	t_node	*last;
	int		counter;

	if (more_than_one(stack))
		return ;
	counter = 0;
	start = stack;
	while (stack->next && ++counter)
		stack = stack->next;
	last = stack;
	stack = start;
	if (counter == 2)
	{
		sa_checker(stack);
		return ;
	}
	last->next = stack->next;
	last->previous->next = NULL;
	stack->next = last;
	last->previous = stack;
	last->next->previous = last;
}

void	rrb_checker(t_node *stack)
{
	t_node	*start;
	t_node	*last;
	int		counter;

	if (more_than_one(stack))
		return ;
	counter = 0;
	start = stack;
	while (stack->next && ++counter)
		stack = stack->next;
	last = stack;
	stack = start;
	if (counter == 2)
	{
		sb_checker(stack);
		return ;
	}
	last->next = stack->next;
	last->previous->next = NULL;
	stack->next = last;
	last->previous = stack;
	last->next->previous = last;
}

void	rrr_checker(t_node *stack_a, t_node *stack_b)
{
	rra_checker(stack_a);
	rrb_checker(stack_b);
}

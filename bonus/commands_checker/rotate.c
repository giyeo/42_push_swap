/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:06:10 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/15 00:32:48 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra_checker(t_node *stack)
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
	stack->next = stack->next->next;
	last->next->next = NULL;
	last->next->previous = last;
	stack->next->previous = stack;
}

void	rb_checker(t_node *stack)
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
	stack->next = stack->next->next;
	last->next->next = NULL;
	last->next->previous = last;
	stack->next->previous = stack;
}

void	rr_checker(t_node *stack_a, t_node *stack_b)
{
	ra_checker(stack_a);
	rb_checker(stack_b);
}

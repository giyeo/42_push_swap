/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:29:11 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/10 00:42:19 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_length(t_node *stack)
{
	int	counter;

	counter = 0;
	while (stack->next)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

int	ordered(t_node *stack_a)
{
	stack_a = stack_a->next;
	while (stack_a->next)
	{
		if (stack_a->index > stack_a->next->index)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	find_next_position(t_node *stack_b)
{
	int	max_index;
	int	max_position;
	int	counter;

	counter = 1;
	stack_b = stack_b->next;
	max_index = stack_b->index;
	while (stack_b->next)
	{
		if (stack_b->index >= max_index)
		{
			max_position = counter;
			max_index = stack_b->index;
		}
		stack_b = stack_b->next;
		counter++;
	}
	if (stack_b->index >= max_index)
	{
		max_position = counter;
		max_index = stack_b->index;
	}
	return (max_position);
}

void	sort(t_node *stack_a, t_node *stack_b)
{
	int	len;

	len = stack_length(stack_a);
	if (more_than_one(stack_a))
		return ;
	if (ordered(stack_a))
		return ;
	if (len == 2)
		if (stack_a->next->index > stack_a->next->next->index)
			sa(stack_a);
	if (len == 3)
		sort_with_3(stack_a);
	else if (len <= 5)
		sort_with_5(stack_a, stack_b);
	else
		sort_with_n(stack_a, stack_b, len);
}

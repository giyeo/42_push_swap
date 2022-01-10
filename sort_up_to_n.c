/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:54:54 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/09 21:55:10 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_with_n(t_node *stack_a, t_node *stack_b, int len)
{
	int	len_b;
	int	position;
	int	swap_signal;
	int	chunk;
	int	up;
	int	down;
	int	last_up;
	int	last_down;
	int	counter;

	chunk = 14;
	if (len > 450)
		chunk = 29;
	up = (len / 2) + chunk;
	down = (len / 2) - chunk;
	last_up = len / 2;
	last_down = len / 2;
	counter = 0;
	while (stack_length(stack_a) > 0)
	{
		if (stack_a->next->index >= last_up && stack_a->next->index < up)
		{
			counter++;
			pb(stack_a, stack_b);
		}
		else if (stack_a->next->index >= down
			&& stack_a->next->index < last_down)
		{
			counter++;
			pb(stack_a, stack_b);
			if (stack_length(stack_b) > 1)
				rb(stack_b);
		}
		else
			ra(stack_a);
		if (counter == chunk * 2)
		{
			last_up = up;
			last_down = down;
			down -= chunk;
			up += chunk;
			counter = 0;
		}
	}
	while (stack_length(stack_b) != 0)
	{
		len_b = stack_length(stack_b);
		position = find_next_position(stack_b);
		swap_signal = 0;
		if (position >= len_b / 2 + 1)
		{
			while (stack_b->next->index != len_b - 1)
			{
				if (stack_b->next->index == len_b - 2)
				{
					pa(stack_a, stack_b);
					swap_signal = 1;
				}
				else
					rrb(stack_b);
			}
		}
		else
		{
			while (stack_b->next->index != len_b - 1)
			{
				if (stack_b->next->index == len_b - 2)
				{
					pa(stack_a, stack_b);
					swap_signal = 1;
				}
				else
					rb(stack_b);
			}
		}
		pa(stack_a, stack_b);
		if (swap_signal)
			sa(stack_a);
	}
}

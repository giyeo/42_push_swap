/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:29:11 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/09 16:38:02 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_with_3(t_node *stack_a)
{
	if (stack_a->next->index > stack_a->next->next->index)
	{
		if (stack_a->next->next->index > stack_a->next->next->next->index)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
		{
			if (stack_a->next->next->next->index > stack_a->next->index)
				sa(stack_a);
			else
				ra(stack_a);
		}
	}
	else
	{
		if (stack_a->next->next->next->index > stack_a->next->index)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
}

int	find_lower(t_node *stack_a)
{
	int	min_index;
	int	min_position;
	int	counter;

	counter = 1;
	stack_a = stack_a->next;
	min_index = stack_a->index;
	while (stack_a->next)
	{
		if (stack_a->index <= min_index)
		{
			min_position = counter;
			min_index = stack_a->index;
		}
		stack_a = stack_a->next;
		counter++;
	}
	if (stack_a->index <= min_index)
	{
		min_position = counter;
		min_index = stack_a->index;
	}
	return (min_position);
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

void	remove_lower(t_node *stack_a, t_node *stack_b, int len)
{
	int	i;
	int	lower_number_position;

	i = 0;
	lower_number_position = find_lower(stack_a);
	if (lower_number_position >= len / 2 + 1)
		while (i++ < len - (lower_number_position - 1))
			rra(stack_a);
	else
		while (i++ < lower_number_position - 1)
			ra(stack_a);
	if (ordered(stack_a))
		exit(0);
	pb(stack_a, stack_b);
}

void	sort_with_5(t_node *stack_a, t_node *stack_b)
{
	int	len;
	int	len2;

	len = stack_length(stack_a);
	len2 = len;
	while (len-- > 3)
		remove_lower(stack_a, stack_b, stack_length(stack_a));
	if (!ordered(stack_a))
		sort_with_3(stack_a);
	while (len2-- > 3)
		pa(stack_a, stack_b);
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

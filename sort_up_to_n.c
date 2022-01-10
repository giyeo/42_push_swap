/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:41:35 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/09 23:59:21 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct sort
{
	int	up;
	int	down;
	int	last_up;
	int	last_down;
	int	len;
}	t_sort;

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

void	bring_back_to_stack_a(t_node *stack_a, t_node *stack_b)
{
	int	len_b;
	int	position;
	int	swap_signal;

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

int	send_to_stack_b(t_node *stack_a, t_node *stack_b, int counter, int mode)
{
	pb(stack_a, stack_b);
	if (stack_length(stack_b) > 1 && mode)
		rb(stack_b);
	return (counter + 1);
}

void	send_chunks_to_stack_b(t_node *stack_a, t_node *stack_b,
								t_sort *data, int chunk)
{
	int	counter;

	counter = 0;
	while (stack_length(stack_a) > 0)
	{
		if (stack_a->next->index >= data->last_up
			&& stack_a->next->index < data->up)
			counter = send_to_stack_b(stack_a, stack_b, counter, 0);
		else if (stack_a->next->index >= data->down
			&& stack_a->next->index < data->last_down)
			counter = send_to_stack_b(stack_a, stack_b, counter, 1);
		else
			ra(stack_a);
		if (counter == chunk * 2)
		{
			data->last_up = data->up;
			data->last_down = data->down;
			data->down -= chunk;
			data->up += chunk;
			counter = 0;
		}
	}
}

void	sort_with_n(t_node *stack_a, t_node *stack_b, int len)
{
	int		chunk;
	t_sort	data;

	chunk = 14;
	if (len > 450)
		chunk = 29;
	data.up = (len / 2) + chunk;
	data.down = (len / 2) - chunk;
	data.last_up = len / 2;
	data.last_down = len / 2;
	send_chunks_to_stack_b(stack_a, stack_b, &data, chunk);
	bring_back_to_stack_a(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:51:55 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/15 12:31:05 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	pb(stack_a, stack_b);
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

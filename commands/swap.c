/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:08:58 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/09 15:09:06 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sa(s_node *stack)
{
	int	value1;

	if (stack->next)
	{
		if (stack->next->next)
		{
			value1 = stack->next->value;
			stack->next->value = stack->next->next->value;
			stack->next->next->value = value1;
			value1 = stack->next->index;
			stack->next->index = stack->next->next->index;
			stack->next->next->index = value1;
			print_command("sa");
		}
	}
}

void	sb(s_node *stack)
{
	int	value1;

	if (stack->next)
	{
		if (stack->next->next)
		{
			value1 = stack->next->value;
			stack->next->value = stack->next->next->value;
			stack->next->next->value = value1;
			value1 = stack->next->index;
			stack->next->index = stack->next->next->index;
			stack->next->next->index = value1;
			print_command("sb");
		}
	}
}

void	ss(s_node *stack_a, s_node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

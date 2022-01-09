/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:58:58 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/09 15:57:49 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	pb(t_node *stack_a, t_node *stack_b)
{
	t_node	*node;
	t_node	*to_free;

	if (more_than_one(stack_a))
		return ;
	node = (t_node *)malloc(sizeof(t_node));
	to_free = stack_a->next;
	if (stack_b->next == NULL)
	{
		stack_b->next = node;
		stack_b->next->value = stack_a->next->value;
		stack_b->next->index = stack_a->next->index;
		stack_b->next->previous = stack_b;
		stack_b->next->next = NULL;
	}
	else
	{
		node->value = stack_a->next->value;
		node->index = stack_a->next->index;
		node->next = stack_b->next;
		stack_b->next = node;
		node->previous = stack_b;
		node->next->previous = node;
	}
	if (stack_a->next->next == NULL)
		stack_a->next = NULL;
	else
	{
		stack_a->next = stack_a->next->next;
		stack_a->next->previous = stack_a;
	}
	print_command("pb");
	free(to_free);
}

void	pa(t_node *stack_a, t_node *stack_b)
{
	t_node	*node;
	t_node	*to_free;

	if (more_than_one(stack_b))
		return ;
	node = (t_node *)malloc(sizeof(t_node));
	to_free = stack_b->next;
	if (stack_a->next == NULL)
	{
		stack_a->next = node;
		stack_a->next->value = stack_b->next->value;
		stack_a->next->index = stack_b->next->index;
		stack_a->next->previous = stack_a;
		stack_a->next->next = NULL;
	}
	else
	{
		node->value = stack_b->next->value;
		node->index = stack_b->next->index;
		node->next = stack_a->next;
		stack_a->next = node;
		node->previous = stack_a;
		node->next->previous = node;
	}
	if (stack_b->next->next == NULL)
		stack_b->next = NULL;
	else
	{
		stack_b->next = stack_b->next->next;
		stack_b->next->previous = stack_b;
	}
	print_command("pa");
	free(to_free);
}

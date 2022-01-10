/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:58:58 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/09 21:21:25 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	px_operation_case_null(t_node *dest_stack, t_node *src_stack,
								t_node *new_node)
{
	dest_stack->next = new_node;
	dest_stack->next->value = src_stack->next->value;
	dest_stack->next->index = src_stack->next->index;
	dest_stack->next->previous = dest_stack;
	dest_stack->next->next = NULL;
}

void	px_operation(t_node *dest_stack, t_node *src_stack, t_node *new_node)
{
	new_node->value = src_stack->next->value;
	new_node->index = src_stack->next->index;
	new_node->next = dest_stack->next;
	dest_stack->next = new_node;
	new_node->previous = dest_stack;
	new_node->next->previous = new_node;
}

void	pb(t_node *stack_a, t_node *stack_b)
{
	t_node	*node;
	t_node	*to_free;

	if (more_than_one(stack_a))
		return ;
	node = (t_node *)malloc(sizeof(t_node));
	to_free = stack_a->next;
	if (stack_b->next == NULL)
		px_operation_case_null(stack_b, stack_a, node);
	else
		px_operation(stack_b, stack_a, node);
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
		px_operation_case_null(stack_a, stack_b, node);
	else
		px_operation(stack_a, stack_a, node);
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

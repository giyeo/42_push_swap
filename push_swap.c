/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:28:11 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/09 15:28:24 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	errors_handler(int argc, char *argv[])
{
	isfewarg_handler(argc);
	isnumber_handler(argc, argv);
	isbigger_handler(argc, argv);
	isduplic_handler(argc, argv);
}

int	main(int argc, char *argv[])
{
	s_node	*stack_a;
	s_node	*stack_b;

	errors_handler(argc, argv);
	stack_a = init_stack();
	stack_b = init_stack();
	populate(stack_a, argc, argv, index_it(argc, argv));
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 03:23:59 by rpaulino          #+#    #+#             */
/*   Updated: 2021/10/07 03:24:01 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	last_to_first_n();

void	first_to_last_n();

void	put_on_top_of_n();

void	swap_the_top_of_n(char *stack_a, char *stack_b);

void	fill_stack_a(char *stack_a, int size_of_stack, char *argv[])
{
	int	i;

	i = 0;
	while (i < size_of_stack)
	{
		stack_a[i] = *argv[i + 1];
		i++;
	} 
	stack_a[i] = '\0';
}

int main(int argc, char *argv[])
{
	int		size_of_stack;
	char	*stack_a;
	char	*stack_b;

	size_of_stack = argc - 1;
	stack_a = (char *)malloc(size_of_stack * sizeof(int) + 1);
	stack_b = (char *)malloc(size_of_stack * sizeof(int) + 1);
	fill_stack_a(stack_a, size_of_stack, argv);
	printf("%s\n", stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
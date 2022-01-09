/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yprint_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:51:03 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/09 16:11:53 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_stack(t_node *stack)
{
	char	*temp;
	char	s;

	s = ' ';
	temp = ft_itoa(stack->index);
	write(1, temp, ft_strlen(temp));
	write(1, &s, 1);
	free(temp);
	return (1);
}

void	print_stack_foot(void)
{
	char	*sep;
	char	*names;

	sep = "- -\n";
	names = "a b\n";
	write(1, sep, 4);
	write(1, names, 4);
	write(1, sep, 4);
}

void	print_stacks(t_node *stack_a, t_node *stack_b)
{
	int		printed;
	char	temp;
	char	*s;

	temp = '\n';
	printed = 1;
	while (printed)
	{
		printed = 0;
		if (stack_a->next)
		{
			stack_a = stack_a->next;
			printed = print_stack(stack_a);
		}
		else
		{
			s = "  ";
			if (stack_b->next)
				write(1, s, 2);
		}
		if (stack_b->next)
		{
			stack_b = stack_b->next;
			printed = print_stack(stack_b);
		}
		if (printed)
			write(1, &temp, 1);
	}
	print_stack_foot();
}

int	print_command(char *name)
{
	static int	count = 0;
	static int	check_a = 0;
	static int	check_b = 0;
	char		new_line;

	new_line = '\n';
	if (ft_strcmp(name, "ra"))
	{
		if (check_a)
		{
			write(1, name, ft_strlen(name));
			write(1, &new_line, 1);
		}
		check_a = 1;
	}
	else if (ft_strcmp(name, "rb"))
	{
		if (check_b)
		{
			write(1, name, ft_strlen(name));
			write(1, &new_line, 1);
		}
		check_b = 1;
	}
	else
	{
		if (check_a)
		{
			write(1, "ra", 2);
			write(1, &new_line, 1);
		}
		if (check_b)
		{
			write(1, "rb", 2);
			write(1, &new_line, 1);
		}
		check_a = 0;
		check_b = 0;
		write(1, name, ft_strlen(name));
		write(1, &new_line, 1);
	}
	if (check_a && check_b)
	{
		check_a = 0;
		check_b = 0;
		write(1, "rr", 2);
		write(1, &new_line, 1);
	}
	count++;
	return (0);
}

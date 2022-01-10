/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:51:03 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/09 21:38:19 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_print_rx(char *name, char new_line, int check)
{
	if (check)
	{
		write(1, name, ft_strlen(name));
		write(1, &new_line, 1);
	}
	return (1);
}

void	case_print(char *name, char new_line, int check_a, int check_b)
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
	write(1, name, ft_strlen(name));
	write(1, &new_line, 1);
}

int	print_command(char *name)
{
	static int	check_a = 0;
	static int	check_b = 0;
	char		new_line;

	new_line = '\n';
	if (ft_strcmp(name, "ra"))
		check_a = case_print_rx(name, new_line, check_a);
	else if (ft_strcmp(name, "rb"))
		check_b = case_print_rx(name, new_line, check_b);
	else
	{
		case_print(name, new_line, check_a, check_b);
		check_a = 0;
		check_b = 0;
	}
	if (check_a && check_b)
	{
		check_a = 0;
		check_b = 0;
		write(1, "rr", 2);
		write(1, &new_line, 1);
	}
	return (0);
}

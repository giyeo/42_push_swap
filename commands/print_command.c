/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:51:03 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/10 00:44:38 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	case_print_rx(char *string, char new_line, int check)
{
	if (check)
	{
		write(1, string, ft_strlen(string));
		write(1, &new_line, 1);
	}
	return (1);
}

void	case_print(char *string, char new_line, int check_ra, int check_rb)
{
	if (check_ra)
	{
		write(1, "ra", 2);
		write(1, &new_line, 1);
	}
	if (check_rb)
	{
		write(1, "rb", 2);
		write(1, &new_line, 1);
	}
	write(1, string, ft_strlen(string));
	if (ft_strcmp(string, ""))
		return ;
	write(1, &new_line, 1);
}

int	print_command(char *string)
{
	static int	check_ra = 0;
	static int	check_rb = 0;
	char		new_line;

	new_line = '\n';
	if (ft_strcmp(string, "ra"))
		check_ra = case_print_rx(string, new_line, check_ra);
	else if (ft_strcmp(string, "rb"))
		check_rb = case_print_rx(string, new_line, check_rb);
	else
	{
		case_print(string, new_line, check_ra, check_rb);
		check_ra = 0;
		check_rb = 0;
	}
	if (check_ra && check_rb)
	{
		check_ra = 0;
		check_rb = 0;
		write(1, "rr", 2);
		write(1, &new_line, 1);
	}
	return (0);
}

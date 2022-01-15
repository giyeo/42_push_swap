/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:13:23 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/15 13:53:09 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(void)
{
	char	*error;
	char	temp;

	error = "Error";
	temp = '\n';
	write(1, error, 5);
	write(1, &temp, 1);
	exit(1);
}

void	isbigger_handler(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi_long(argv[i]) > 2147483647)
			error();
		if (ft_atoi_long(argv[i]) < -2147483648)
			error();
		i++;
	}
}

void	isduplic_handler(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
			if (ft_strcmp(argv[i], argv[j++]))
				error();
		i++;
	}
}
#include <stdio.h>
void	isnumber_handler(int argc, char *argv[])
{
	int		i;
	int		j;
	int		lenght;
	char	*string;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		string = argv[i++ + 1];
		lenght = ft_strlen(string);
		if (lenght == 0)
			error();
		while (j < lenght)
		{
			if (!ischardigit(string[j++]))
				error();
		}
	}
}

void	isfewarg_handler(int argc)
{
	if (argc == 1)
		exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:24:49 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/09 21:47:59 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct index
{
	int	value;
	int	index;
}	t_index;

t_index	*fill_array(int argc, t_index *array, int i, int j)
{
	int		minor;
	int		major;

	major = INT_MIN;
	while (j < argc - 1)
	{
		minor = INT_MAX;
		while (++i < argc - 1)
		{
			if (array[i].value <= minor && array[i].value > major)
			{
				minor = array[i].value;
				array[i].index = j;
			}
		}
		j++;
		major = minor;
		i = -1;
	}
	return (array);
}

int	*index_it(int argc, char *argv[])
{
	int		i;
	int		j;
	int		*return_it;
	t_index	*array;

	array = (t_index *)malloc(sizeof(t_index) * (argc - 1));
	return_it = (int *)malloc(sizeof(int) * (argc - 1));
	i = -1;
	j = 0;
	while (++i < argc - 1)
		array[i].value = atoi(argv[i + 1]);
	i = -1;
	array = fill_array(argc, array, i, j);
	while (++i < argc - 1)
		return_it[i] = array[i].index;
	free(array);
	return (return_it);
}

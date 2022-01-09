/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_llists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:19:11 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/09 15:19:12 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	more_than_one(s_node *stack)
{
	if (stack->next == NULL)
		return (1);
	return (0);
}

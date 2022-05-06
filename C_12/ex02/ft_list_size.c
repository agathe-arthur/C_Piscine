/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:44:24 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/30 17:08:47 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*visit;
	int		count;

	count = 0;
	visit = begin_list;
	while (visit != NULL)
	{
		visit = visit->next;
		count++;
	}
	return (count);
}

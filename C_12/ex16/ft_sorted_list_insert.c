/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:33:34 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/31 15:39:32 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new;
	t_list	*previous;
	t_list	*visit;

	if (!(begin_list))
		return ;
	visit = *begin_list;
	while (visit != NULL)
	{
		if ((*cmp)(visit->data, data) > 0)
			break ;
		previous = visit;
		visit = visit->next;
	}
	new = ft_create_elem(data);
	new->next = visit;
	if (visit != *begin_list)
		previous->next = new;
	else
		*begin_list = new;
}

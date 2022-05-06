/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:44:10 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/31 20:32:36 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void	ft_win_lines(t_list **p, t_list **v)
{
	*p = *v;
	*v = (*v)->next;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*previous;
	t_list	*visit;
	t_list	*nxt;

	if (!(begin_list))
		return ;
	visit = *begin_list;
	while (visit && visit->next != NULL)
	{
		nxt = visit->next;
		if ((*cmp)(visit->data, nxt->data) > 0)
		{
			visit->next = nxt->next;
			nxt->next = visit;
			if (visit == *begin_list)
				*begin_list = nxt;
			else
				previous->next = nxt;
			visit = *begin_list;
		}
		else
			ft_win_lines(&previous, &visit);
	}
}

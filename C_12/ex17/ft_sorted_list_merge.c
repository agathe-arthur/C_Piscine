/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:33:34 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/31 20:35:03 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

void	ft_win_lines(t_list **previous, t_list **visit)
{
	*previous = *visit;
	*visit = (*visit)->next;
}

void	ft_place(t_list *v2, t_list *v, t_list *p, t_list **begin_list)
{
	v2->next = v;
	if (p)
		p->next = v2;
	else if (begin_list)
		*begin_list = v2;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
int (*cmp)())
{
	t_list	*previous;
	t_list	*visit;
	t_list	*visit2;

	previous = NULL;
	if (!(begin_list1 && *begin_list1))
	{
		*begin_list1 = begin_list2;
		return ;
	}
	visit = *begin_list1;
	visit2 = begin_list2;
	while (visit && visit2)
	{
		if ((*cmp)(visit->data, visit2->data) > 0)
		{
			ft_place(visit2, visit, previous, begin_list1);
			previous = visit2;
			visit2 = visit2->next;
		}
		else
			ft_win_lines(&previous, &visit);
	}
	if (visit2)
		previous->next = visit2;
}

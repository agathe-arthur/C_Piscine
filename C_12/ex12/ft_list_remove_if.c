/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:45:27 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/31 17:00:48 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stddef.h>

void	ft_win_lines(t_list **previous, t_list *visit, int *begin)
{
	*previous = visit;
	*begin = 1;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *))
{
	t_list	*previous;
	t_list	*visit;
	t_list	*nxt;
	int		begin;

	if (!(begin_list))
		return ;
	begin = 0;
	visit = *begin_list;
	while (visit != NULL)
	{
		nxt = visit->next;
		if (!(*cmp)(visit->data, data_ref))
		{
			(*free_fct)(visit->data);
			free(visit);
			if (!begin)
				*begin_list = nxt;
			else
				previous->next = nxt;
		}
		else
			ft_win_lines(&previous, visit, &begin);
		visit = nxt;
	}
}

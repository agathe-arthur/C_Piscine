/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:31:27 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/31 20:28:24 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*previous;
	t_list	*visit;
	t_list	*nxt;

	if (!(begin_list))
		return ;
	visit = *begin_list;
	if (visit)
		nxt = (*begin_list)->next;
	else
		return ;
	while (nxt != NULL)
	{
		previous = visit;
		visit = nxt;
		nxt = visit->next;
		visit->next = previous;
	}
	(*begin_list)->next = NULL;
	*begin_list = visit;
}

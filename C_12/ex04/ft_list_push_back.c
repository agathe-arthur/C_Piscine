/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:23:25 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/31 15:06:43 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;
	t_list	*visit;

	if (!(begin_list))
		return ;
	last = ft_create_elem(data);
	visit = *begin_list;
	if (visit != NULL)
	{
		while (visit->next != NULL)
			visit = visit->next;
		visit->next = last;
	}
	else
		*begin_list = last;
}

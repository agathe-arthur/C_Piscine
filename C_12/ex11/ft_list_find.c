/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:30:39 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/30 17:17:00 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*visit;

	visit = begin_list;
	while (visit != NULL)
	{
		if (!((*cmp)(visit->data, data_ref)))
			return (visit);
		visit = visit->next;
	}
	return (visit);
}

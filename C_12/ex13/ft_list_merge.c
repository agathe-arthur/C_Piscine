/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:40:23 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/31 20:29:04 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*visit;

	if (begin_list1)
	{
		visit = *begin_list1;
		if (visit != NULL)
		{
			while (visit->next != NULL)
				visit = visit->next;
			visit->next = begin_list2;
			return ;
		}
	}
	*begin_list1 = begin_list2;
}

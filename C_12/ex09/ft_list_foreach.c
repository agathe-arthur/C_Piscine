/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 02:08:41 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/30 17:15:09 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*visit;

	visit = begin_list;
	while (visit != NULL)
	{
		(*f)(visit->data);
		visit = visit->next;
	}
}

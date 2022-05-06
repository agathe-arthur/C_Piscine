/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:41:19 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/31 14:06:27 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*begin_list;
	t_list	*previous;
	t_list	*list;

	i = size - 1;
	if (i >= 0)
		begin_list = ft_create_elem(strs[i]);
	else
		return (NULL);
	list = begin_list;
	i--;
	while (i >= 0)
	{
		previous = list;
		list = ft_create_elem(strs[i]);
		previous->next = list;
		i--;
	}
	return (begin_list);
}

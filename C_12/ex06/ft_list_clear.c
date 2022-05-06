/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:13:14 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/30 17:11:55 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*visit;

	visit = begin_list;
	while (visit != NULL)
	{
		(*free_fct)(begin_list->data);
		visit = begin_list->next;
		free(begin_list);
		begin_list = visit;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:24:01 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/31 15:09:53 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*visit;

	i = 0;
	if (!begin_list)
		return (NULL);
	visit = begin_list;
	while (i < nbr && visit->next != NULL)
	{
		visit = visit->next;
		i++;
	}
	if (visit->next == NULL && nbr != i)
		return (NULL);
	return (visit);
}

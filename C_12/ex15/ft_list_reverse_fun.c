/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:33:36 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/31 15:37:40 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

int	ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*visit;

	count = 0;
	visit = begin_list;
	while (visit != NULL)
	{
		count++;
		visit = visit->next;
	}
	return (count);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*visit;

	i = 0;
	visit = begin_list;
	while (i < nbr && visit->next != NULL)
	{
		visit = visit->next;
		i++;
	}
	return (visit);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		size;
	void	*temp;
	t_list	*visit1;
	t_list	*visit2;

	size = ft_list_size(begin_list);
	i = 0;
	while (i < size / 2)
	{
		visit1 = ft_list_at(begin_list, i);
		visit2 = ft_list_at(begin_list, size - i - 1);
		temp = visit1->data;
		visit1->data = visit2->data;
		visit2->data = temp;
		i++;
	}
}

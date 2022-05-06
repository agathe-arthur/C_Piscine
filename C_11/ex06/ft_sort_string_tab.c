/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:18:04 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/29 15:08:15 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);

void	ft_sort_string_tab(char **tab)
{
	char	*temp;
	int		i;

	i = 0;
	if (!(tab[i] && tab[i + 1]))
		return ;
	while (tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]))
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
				return (1);
			return (0);
		}
		i++;
	}
	if (s1[i])
		return (1);
	return (0);
}

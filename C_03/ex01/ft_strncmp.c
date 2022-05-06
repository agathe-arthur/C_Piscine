/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:38:53 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/14 16:23:01 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1 && s2 && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if ((s1[i] == '\0' && s2[i] == '\0') || i + 1 == n)
			return (0);
		i++;
	}
	if (n == 0)
		return (0);
	if (s1)
		return (s1[i]);
	if (s2)
		return (-(s2[i]));
	return (0);
}

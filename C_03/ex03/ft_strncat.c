/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:00:17 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/14 16:03:27 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest && dest[i] != '\0')
		i++;
	j = 0;
	while (src && src[j] != '\0' && j < nb)
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:59:26 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/22 13:52:45 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	len_dest;
	unsigned int	len_src;

	j = 0;
	len_src = ft_strlen(src);
	if (!size)
		return (len_src);
	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (size + len_src);
	while (src[j] != '\0' && j < size - len_dest - 1)
	{
		dest[len_dest + j] = src[j];
		j++;
	}
	dest[len_dest + j] = '\0';
	return (len_dest + len_src);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

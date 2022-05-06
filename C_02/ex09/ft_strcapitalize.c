/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:07:42 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/13 21:21:06 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
int		ft_is_up(char c);
int		ft_is_low(char c);
int		ft_is_num(char c);
void	ft_init_letter(int *no_letter, char *str, int i);

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		no_letter;

	i = 0;
	no_letter = 1;
	while (str && str[i] != '\0')
	{
		ft_init_letter(&no_letter, str, i);
		if (ft_is_up(str[i]))
		{
			if (!no_letter)
				str[i] = str[i] + 32;
			else
				no_letter = 0;
		}
		if (ft_is_low(str[i]) && no_letter)
		{
			str[i] = str[i] - 32;
			no_letter = 0;
		}
		i++;
	}
	return (str);
}

void	ft_init_letter(int *no_letter, char *str, int i)
{	
	if (!(ft_is_up(str[i]) || ft_is_low(str[i]) || ft_is_num(str[i])))
		*no_letter = 1;
	if (ft_is_num(str[i]))
		*no_letter = 0;
}

int	ft_is_up(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_is_low(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

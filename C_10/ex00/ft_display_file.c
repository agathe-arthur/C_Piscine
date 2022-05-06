/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagathe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:50:17 by aagathe           #+#    #+#             */
/*   Updated: 2022/03/23 19:01:26 by aagathe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	int		lu;
	char	buffer;

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			write(2, "Cannot read file.\n", 18);
		else
		{
			lu = read(fd, &buffer, 1);
			while (lu > 0)
			{
				write(1, &buffer, 1);
				lu = read(fd, &buffer, 1);
			}
			close(fd);
		}
	}
	return (0);
}

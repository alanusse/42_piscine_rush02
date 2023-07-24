/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:59:53 by mpovill-          #+#    #+#             */
/*   Updated: 2023/07/23 23:11:58 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str);

int	get_number(int fd, char num, char *str)
{
	char	c[0];

	if (num != *str)
		return (-1);
	str++;
	while (*str != '\0')
	{
		if (!read(fd, c, 1))
			return (0);
		if (*str == c[0])
			str++;
		else
			return (-1);
	}
	return (1);
}

int	read_in_between(int fd, char *buff)
{
	if (!read(fd, buff, 1))
		return (0);
	while (buff[0] == ' ' || buff[0] == ':')
	{
		if (!read(fd, buff, 1))
			return (0);
	}
	return (1);
}

char	read_end_of_line(int fd)
{
	char	buff[1];

	if (!read(fd, buff, 1))
		return (0);
	while (buff[0] != '\n')
	{
		if (!read(fd, buff, 1))
			return (0);
	}
	if (!read(fd, buff, 1))
		return (0);
	return (buff[0]);
}

int	loop_show_char(int fd, char *buff, char *str_to_search)
{
	int	num;

	num = get_number(fd, buff[0], str_to_search);
	if (num == 0)
		return (0);
	else if (num == 1)
	{
		if (!read_in_between(fd, buff))
			return (0);
		while (buff[0] != '\n')
		{
			write(1, &buff[0], 1);
			if (!read(fd, buff, 1))
				return (0);
		}
	}
	else if (num == -1)
	{
		buff[0] = read_end_of_line(fd);
		if (buff[0] == 0)
			return (0);
		return (1);
	}
	return (-1);
}

int	search_in_file(char *str_to_search, char *name)
{
	int		fd;
	char	buff[1];
	int		num;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!read(fd, buff, 1))
		return (0);
	num = 1;
	while (num == 1)
		num = loop_show_char(fd, buff, str_to_search);
	close(fd);
	write(1, " ", 1);
	if (num == 0)
		return (0);
	return (1);
}

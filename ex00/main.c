/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:31:50 by mpovill-          #+#    #+#             */
/*   Updated: 2023/07/22 17:31:57 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_manage_str(char *str);

void	error(void)
{
	write(1, "Error\n", 6);
}

int	validate_input(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		error();
		return (0);
	}
	if (!(validate_input(argv[1])))
	{
		error();
		return (0);
	}
	ft_manage_str(argv[1]);
	return (0);
}

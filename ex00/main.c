/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:31:50 by mpovill-          #+#    #+#             */
/*   Updated: 2023/07/23 23:04:19 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	read_file(char *name);

int		ft_lookup_numbers_dictionary(char *str, char *name);

void	ft_putstr(char *str);

void	error(void)
{
	write(1, "Error\n", 6);
}

void	dict_error(void)
{
	write(1, "DictError\n", 10);
}

void	enter_param(char *param1, char *param2)
{
	if (!ft_lookup_numbers_dictionary(param1, param2))
		dict_error();
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

int	main(int argc, char *argv[])
{
	char	*ptr;

	if (argc < 2 || argc > 3)
	{
		error();
		return (0);
	}
	if (argc == 2)
		ptr = argv[1];
	else
		ptr = argv[2];
	if (!validate_input(ptr))
	{
		error();
		return (0);
	}
	if (argc == 2)
		enter_param(argv[1], "numbers.dict");
	else
		enter_param(argv[2], argv[1]);
	return (0);
}

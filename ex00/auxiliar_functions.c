/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:02:26 by mpovill-          #+#    #+#             */
/*   Updated: 2023/07/23 23:13:24 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				search_in_file(char *str, char *name);
int				recursive_create_array(int nbr, char *str, int index);
char			*copy_str(char *str_to_copy, int num);

char	*copy_str_and_add(char *str_to_copy)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 3);
	str[0] = str_to_copy[0];
	str[1] = '0';
	str[2] = '\0';
	return (str);
}

int	search_all(unsigned int digits, char *str, char *name)
{
	int	aux;

	aux = 1;
	if (*str != '0')
	{
		if (digits < 10)
			aux = search_in_file(copy_str(str, 1), name);
		else if (digits < 100)
		{
			if (*str == '1')
			{
				aux = search_in_file(copy_str(str, 2), name);
				if (aux != 0)
					aux = -1;
			}
			else
				aux = search_in_file(copy_str_and_add(str), name);
		}
		else
		{
			aux = search_in_file(copy_str(str, 1), name);
			aux = search_in_file("100", name);
		}
	}
	return (aux);
}

int	search_number(unsigned int digits, char *str, char *name)
{
	int	*i;
	int	num;
	int	aux;

	num = 0;
	i = &num;
	while (digits > 0)
	{
		aux = search_all(digits, str, name);
		if (aux == 0)
			return (0);
		if (aux == -1)
		{
			*i += 1;
			digits = 0;
		}
		str++;
		*i += 1;
		digits /= 10;
	}
	return (num);
}

unsigned int	update_digits(unsigned int digits, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		digits = digits / 10;
		j++;
	}
	return (digits);
}

int	check_range_not_zero(int number, char *str)
{
	if (number == 100 && str[0] == '0' && str[1] == '0' && str[2] == '0')
		return (0);
	else if (number == 10 && str[0] == '0' && str[1] == '0')
		return (0);
	else if (number == 1 && str[0] == '0')
		return (0);
	return (1);
}

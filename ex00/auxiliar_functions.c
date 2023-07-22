/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:02:26 by mpovill-          #+#    #+#             */
/*   Updated: 2023/07/22 18:04:05 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str);
int	ft_strlen(char *str);


/*
 * This will never get an empty string. It should always be correct
 */
unsigned int	get_digits(char *str)
{
	unsigned int	mult;

	mult = 1;
	str++;
	while (*str >= '0' && *str <= '9')
	{
		mult *= 10;
		str++;
	}
	return (mult);
}

/*
 * Called at *ft_nbr_to_char. Used to operate
 */
int	recursive_create_array(int nbr, char *str, int index)
{
	if ((nbr / 10) < 1)
		*str = nbr + '0';
	else
	{
		index = recursive_create_array(nbr / 10, str, index);
		*(str + index) = (nbr % 10) + '0';
	}
	index++;
	return (index);
}

/*
 * Converts an int to an array of char
 */
char	*ft_nbr_to_char(int nb, int size)
{
	char	*str;
	int		index;

	str = (char *)malloc(sizeof(char) * size);
	//check null??
	index = 0;
	if (nb < 0)
	{
		*str = '-';
		index++;
	}
	index = recursive_create_array(nb, str, index);
	*(str + index) = '\0';
	return (str);
}

/*
 * This manages the string we pass as an argument and gets
 * all the numbers to search and display at the dictionary
 */
void	ft_manage_str(char *str)
{
	int				aux;
	int				length;
	unsigned int	digits;
	char			*str_aux;

	length = ft_strlen(str);
	digits = get_digits(str);
	while (digits > 0)
	{
		if (digits < 100)
		{
			if (*str <= '2' && *str > '0')
			{
				//add num together
				//str_aux = ft_nbr_to_char(digits, length);
				ft_putstr(str);
				digits = 0;
			}
		}
		else if (digits == 1 && *str > '0')
		{
			write(1, str, 1);
			write(1, "\n", 1);
		}
		else
		{
			aux = *str;
			if (aux != '0')
			{
				write(1, &aux, 1);
				write(1, "\n", 1);
				str_aux = ft_nbr_to_char(digits, length);
				ft_putstr(str_aux);
			}
		}
		digits /= 10;
		str++;
	}
}

void	search_two_digits(char first, char second)
{
	//write(1, &first, 1);
	//write(1, &second, 1);
}

int	search_number(unsigned int digits, char *str)
{
	char *str_aux;
	int	i;

	i = 0;
	while (digits > 0)
	{
		if (*str != '0')
		{
			if (digits < 10)
			{
				write(1, str, 1);
				write(1, "\n", 1);
			}
			else if (digits < 100)
			{
				if (*str == '1')
				{
					write(1, str, 2);
					write(1, "\n", 1);
					digits = 1;
					i++;
				}
				else
				{
					write(1, str, 1);
					write(1, "0", 1);
					write(1, "\n", 1);
				}
			}
			else
			{
				write(1, str, 1);
				write(1, "\n", 1);
				write(1, "100", 3);
				write(1, "\n", 1);
			}
		}
		str++;
		i++;
		digits /= 10;
	}
	return (i);
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

void	ft_lookup_numbers_dictionary(char *str)
{
	unsigned int	digits;
	int	i;
	int	length;

	length = ft_strlen(str);
	digits = get_digits(str);
	while (digits > 0)
	{
		if (digits >= 1000000)
		{
			i = search_number(digits / 1000000, str);
			str = str + i;
			digits = update_digits(digits, i);
			write(1, "1000000", 7);
			write(1, "\n", 1);
		}
		else if (digits >= 1000)
		{
			i = search_number(digits / 1000, str);
			str = str + i;
			digits = update_digits(digits, i);
			write(1, "1000", 4);
			write(1, "\n", 1);
		}
		else
		{
			i = search_number(digits, str);
			str = str + i;
			digits = update_digits(digits, i);
		}
	}
}

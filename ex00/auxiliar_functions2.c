/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:56:27 by aglanuss          #+#    #+#             */
/*   Updated: 2023/07/23 22:32:11 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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
 * null??
 * free??
 */
char	*ft_nbr_to_char(int nb, int size)
{
	char	*str;
	int		index;

	str = (char *)malloc(sizeof(char) * size);
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

char	*copy_str(char *str_to_copy, int num)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (num + 1));
	while (i < num)
	{
		str[i] = str_to_copy[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

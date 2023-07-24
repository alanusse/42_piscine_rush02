/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_aux_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:01:56 by mpovill-          #+#    #+#             */
/*   Updated: 2023/07/23 14:24:42 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
 * Display the array
 */
void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, &*str, 1);
		str++;
	}
	write(1, "\n", 1);
}

/*
 * Returns the length of a string
 */
int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

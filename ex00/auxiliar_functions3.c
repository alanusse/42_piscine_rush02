/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_functions3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:52:13 by aglanuss          #+#    #+#             */
/*   Updated: 2023/07/23 23:06:23 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_nbr_to_char(int nb, int size);
int				search_in_file(char *str, char *name);
int				search_number(unsigned int digits, char *str, char *name);
int				check_range_not_zero(int number, char *str);
unsigned int	update_digits(unsigned int digits, int i);
unsigned int	get_digits(char *str);

int	ft_convert_and_lookup(unsigned int range, int length, char *name)
{
	char	*ptr;

	ptr = ft_nbr_to_char(range, length);
	if (!search_in_file(ptr, name))
		return (0);
	return (1);
}

int	ft_lookup(unsigned int digits, char *str, char *name, unsigned int range)
{
	int	length;
	int	i;

	length = 10;
	i = 0;
	while (digits > 0)
	{
		if (digits >= range)
		{
			i = search_number(digits / range, str, name);
			if (i == 0)
				return (0);
			if (check_range_not_zero(digits / range, str))
				if (range != 1)
					if (!ft_convert_and_lookup(range, length, name))
						return (0);
			str = str + i;
			digits = update_digits(digits, i);
		}
		range = range / 1000;
		length -= 3;
	}
	return (1);
}

int	ft_lookup_numbers_dictionary(char *str, char *name)
{
	unsigned int	digits;
	unsigned int	range;

	range = 1000000000;
	digits = get_digits(str);
	return (ft_lookup(digits, str, name, range));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:34:01 by jbach             #+#    #+#             */
/*   Updated: 2022/03/20 16:03:49 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	count_numbers(int n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	negative(int n)
{
	int	negative;

	negative = 0;
	if (n < 0)
		negative = 1;
	return (negative);
}

char	*modulo(int number, int n, char *str)
{
	int	number_all;
	int	n_modulo_new;
	int	n_modulo_old;
	int	j;
	int	i;

	j = 10;
	n_modulo_old = 0;
	i = 0;
	number_all = number;
	while (number >= i)
	{
		n_modulo_new = n % j;
		str[number_all] = ((n_modulo_new - n_modulo_old) / (j / 10)) + '0';
		j = j * 10;
		n_modulo_old = n_modulo_new;
		number_all--;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		number;
	int		number_neg;

	number_neg = negative(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (number_neg == 1)
		n = -n;
	number = count_numbers(n);
	if (number_neg == 1)
		number++;
	str = ft_calloc((number + 2), sizeof(char));
	if (!str)
		return (NULL);
	modulo(number, n, str);
	if (number_neg == 1)
		str[0] = '-';
	if (str)
		return (str);
	return (0);
}

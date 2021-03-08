/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:03:30 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/17 13:31:43 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_number_length_int(int value, int base)
{
	int i;

	i = 0;
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

static char		*ft_itoa_base_result(int value, int base, int length, int flag)
{
	char *buffer;
	char *result;

	buffer = ft_strdup("0123456789ABCDEF");
	if (!(result = (char*)malloc(sizeof(char) * (length + flag + 1))))
		return (NULL);
	if (flag == 1)
	{
		result[0] = '-';
		length++;
	}
	result[length] = '\0';
	while (length > flag)
	{
		result[length - 1] = result[buffer % base];
		length--;
		value /= base;
	}
	free(buffer);
	return (result);
}

char			*ft_itoa_base(int value, int base)
{
	int		length;
	int		flag;

	flag = 0;
	if (value == 0)
		return (ft_strdup("0"));
	if (value == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	if (base < 2 || base > 16)
		return (NULL);
	if (value < 0 && base != 10)
		return (NULL);
	if (value < 0 && base == 10)
	{
		flag = 1;
		value *= -1;
	}
	length = ft_number_length_int(value, base);
	return (ft_itoa_base_result(value, base, length, flag));
}

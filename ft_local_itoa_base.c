/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_local_itoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:56:35 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/25 12:31:10 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_local_itoa_base(unsigned long long value, int base, char letter)
{
	unsigned long	temp;
	int				length;
	char			*string;

	length = 1;
	temp = value;
	while ((temp /= base) >= 1)
		length++;
	if (!(string = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	string[length] = '\0';
	while (length--)
	{
		string[length] = ((value % base) < 10 ?
				((value % base) + '0') : ((value % base) + letter - 10));
		value /= base;
	}
	return (string);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_integer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:21:28 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/24 18:26:48 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned_integer(t_struct *str, va_list ap)
{
	int				length;
	unsigned int	value;
	char			*buffer;

	value = (unsigned int)va_arg(ap, unsigned int);
	buffer = ft_local_itoa_base(value, 10, 'a');
	length = ft_strlen(buffer);
	if (value == 0 && str->precision >= 0)
		length = 0;
	ft_print_converter(str, length);
	if (str->minus == 1)
		ft_print_left_alignment(str, buffer, length);
	else
		ft_print_right_alignment(str, buffer, length);
	free(buffer);
}

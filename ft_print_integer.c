/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:38:27 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/25 12:28:33 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_integer(t_struct *str, va_list ap)
{
	long	value;
	int		length;
	char	*buffer;

	value = (int)va_arg(ap, int);
	if (value < 0)
	{
		value = -value;
		str->flag_minus = 1;
	}
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

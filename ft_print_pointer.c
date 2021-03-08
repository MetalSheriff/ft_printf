/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:29:23 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/25 13:52:43 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer_converter(t_struct *str, int length)
{
	if (str->minus > 0)
		str->zero = 0;
	if (str->precision > length)
		str->precision_to_fill = str->precision - length;
	if (str->width >= length + str->precision_to_fill)
		str->width_to_fill = str->width - length - 2;
}

void	ft_print_pointer(t_struct *str, va_list ap)
{
	char				*buffer;
	unsigned long long	pointer;
	int					length;

	str->pointer = 1;
	pointer = (unsigned long long)va_arg(ap, void*);
	buffer = ft_local_itoa_base(pointer, 16, 'a');
	length = ft_strlen(buffer);
	if ((pointer == 0) && (str->precision >= 0))
	{
		str->null_pointer = 1;
		length--;
	}
	ft_pointer_converter(str, length);
	if (str->minus == 1)
		ft_print_left_alignment(str, buffer, length);
	else
		ft_print_right_alignment(str, buffer, length);
	free(buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:08:01 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/26 13:40:23 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_string_right_alignment(t_struct *str, char *buffer,
int length)
{
	while (str->width_to_fill > 0)
	{
		if (str->zero)
			str->print += (str->zero == 0) ?
					write(1, "-", 1) : write(1, "0", 1);
		else
			str->print += write(1, " ", 1);
		str->width_to_fill--;
	}
	while (length > 0)
	{
		str->print += write(1, buffer, 1);
		buffer++;
		length--;
	}
}

void		ft_print_string_left_alignment(t_struct *str, char *buffer,
int length)
{
	while (length > 0)
	{
		str->print += write(1, buffer, 1);
		buffer++;
		length--;
	}
	while (str->width_to_fill > 0)
	{
		str->print += write(1, " ", 1);
		str->width_to_fill--;
	}
}

void		ft_print_string(t_struct *str, va_list ap)
{
	char	*buffer;
	int		length;

	buffer = (char *)va_arg(ap, char *);
	if (buffer == NULL)
		buffer = "(null)";
	length = ft_strlen(buffer);
	if (str->precision >= 0)
		length = (str->precision < length) ? str->precision : length;
	str->width_to_fill = str->width - length;
	if (str->minus == 1)
		ft_print_string_left_alignment(str, buffer, length);
	else
		ft_print_string_right_alignment(str, buffer, length);
}

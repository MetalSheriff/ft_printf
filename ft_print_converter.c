/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_converter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:28:05 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/26 13:37:26 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_converter(t_struct *str, int length)
{
	str->zero = (str->precision >= 0) ? 0 : str->zero;
	str->zero = (str->minus > 0) ? 0 : str->zero;
	if (str->precision > length)
		str->precision_to_fill = str->precision - length;
	if (str->width != 0)
	{
		if (str->flag_minus == 1)
			str->width_to_fill = str->width -
					str->precision_to_fill - length - 1;
		else
			str->width_to_fill = str->width - str->precision_to_fill - length;
	}
}

void	ft_print_left_alignment(t_struct *str, char *buffer, int length)
{
	if (str->pointer == 1)
		str->print += write(1, "0x", 2);
	if (str->flag_minus == 1)
		str->print += write(1, "-", 1);
	while (str->precision_to_fill > 0)
	{
		str->print += write(1, "0", 1);
		str->precision_to_fill--;
	}
	while (length-- > 0 && str->null_pointer != 1)
	{
		str->print += write(1, buffer, 1);
		buffer++;
	}
	while (str->width_to_fill > 0)
	{
		str->print += (str->zero == 0) ?
				write(1, " ", 1) : write(1, "0", 1);
		str->width_to_fill--;
	}
}

void	ft_print_right_alignment(t_struct *str, char *buffer, int length)
{
	if (str->flag_minus == 1 && str->zero == 1)
		str->print += write(1, "-", 1);
	while (str->width_to_fill > 0)
	{
		str->print += (str->zero == 0) ? write(1, " ", 1) : write(1, "0", 1);
		str->width_to_fill--;
	}
	if (str->pointer == 1)
		str->print += write(1, "0x", 2);
	if (str->flag_minus == 1 && str->zero == 0)
		str->print += write(1, "-", 1);
	while (str->precision_to_fill > 0)
	{
		str->print += write(1, "0", 1);
		str->precision_to_fill--;
	}
	while (length-- > 0 && str->null_pointer != 1)
	{
		str->print += write(1, buffer, 1);
		buffer++;
	}
}

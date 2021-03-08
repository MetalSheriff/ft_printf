/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:35:11 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/25 12:33:59 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_character_converter(t_struct *str)
{
	str->width_to_fill = str->width - 1;
	if (str->minus != 0)
		str->zero = 0;
}

void	ft_print_character(t_struct *str, va_list ap)
{
	unsigned char ch;

	ch = (unsigned char)va_arg(ap, int);
	ft_character_converter(str);
	if (str->minus == 1)
	{
		str->print += write(1, &ch, 1);
		while (str->width_to_fill > 0)
		{
			str->print += (str->zero == 0) ?
					write(1, " ", 1) : write(1, "0", 1);
			str->width_to_fill--;
		}
	}
	else
	{
		while (str->width_to_fill > 0)
		{
			str->print += (str->zero == 0) ?
					write(1, " ", 1) : write(1, "0", 1);
			str->width_to_fill--;
		}
		str->print += write(1, &ch, 1);
	}
}

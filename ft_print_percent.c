/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:43:52 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/26 13:44:36 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_struct *str, char percent)
{
	ft_character_converter(str);
	if (str->minus == 1)
	{
		str->print += write(1, &percent, 1);
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
		str->print += write(1, &percent, 1);
	}
}

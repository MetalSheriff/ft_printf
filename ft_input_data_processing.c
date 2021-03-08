/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_data_processing.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:09:53 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/24 16:25:56 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_input_data_processing(const char *format, t_struct *str,
va_list ap)
{
	while (format[str->position])
	{
		if ((format[str->position] != '%') &&
			(format[str->position]))
			str->print += write(1, &format[str->position++], 1);
		else if (format[str->position] == '%')
		{
			str->position++;
			if (!(ft_strchr("-.*0123456789%cspdiuxX",
				format[str->position])))
				break ;
			ft_parsing_modifiers(format, str, ap);
			ft_parsing_types(format, str, ap);
			ft_flags_reset(str);
		}
	}
	return (str->print);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:27:46 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/24 16:38:54 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parsing_types(const char *format, t_struct *str, va_list ap)
{
	if (format[str->position] == 'd' || format[str->position] == 'i')
		ft_print_integer(str, ap);
	else if (format[str->position] == 'u')
		ft_print_unsigned_integer(str, ap);
	else if (format[str->position] == 'x')
		ft_print_hexadecimal_integer(str, ap, 'a');
	else if (format[str->position] == 'X')
		ft_print_hexadecimal_integer(str, ap, 'A');
	else if (format[str->position] == 'c')
		ft_print_character(str, ap);
	else if (format[str->position] == 's')
		ft_print_string(str, ap);
	else if (format[str->position] == 'p')
		ft_print_pointer(str, ap);
	else if (format[str->position] == '%')
		ft_print_percent(str, '%');
	else
		return ;
	str->position++;
}

void		ft_parsing_flag(const char *format, t_struct *str)
{
	while (format[str->position] == '0' || format[str->position] == '-')
	{
		if (format[str->position] == '0')
			str->zero = 1;
		else if (format[str->position] == '-')
			str->minus = 1;
		str->position++;
	}
}

void		ft_parsing_width(const char *format, t_struct *str, va_list ap)
{
	if (format[str->position] >= '0' && format[str->position] <= '9')
	{
		str->width = ft_atoi(&format[str->position]);
		while (format[str->position] >= '0' && format[str->position] <= '9')
			str->position++;
	}
	else if (format[str->position] == '*')
	{
		str->width = (int)va_arg(ap, int);
		if (str->width < 0)
		{
			str->zero = 0;
			str->width *= -1;
			str->minus = 1;
		}
		str->position++;
	}
}

void		ft_parsing_precision(const char *format, t_struct *str, va_list ap)
{
	if (format[str->position] == '.')
	{
		str->position++;
		if (format[str->position] >= '0' && format[str->position] <= '9')
		{
			str->precision = ft_atoi(&format[str->position]);
			while (format[str->position] >= '0' && format[str->position] <= '9')
				str->position++;
		}
		else if (format[str->position] == '*')
		{
			str->precision = (int)va_arg(ap, int);
			if (str->precision < 0)
				str->precision = -1;
			str->position++;
		}
		else
			str->precision = 0;
	}
}

void		ft_parsing_modifiers(const char *format, t_struct *str, va_list ap)
{
	ft_parsing_flag(format, str);
	ft_parsing_width(format, str, ap);
	ft_parsing_precision(format, str, ap);
}

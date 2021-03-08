/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:01:11 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/26 13:41:18 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			length;
	t_struct	*str;

	if (!(str = (t_struct *)malloc(sizeof(t_struct))))
		return (0);
	ft_struct_reset(str);
	va_start(ap, format);
	if (!(format[0]) || (format[0] == '%' && ft_strlen(format) == 1))
		return (0);
	else
		length = ft_input_data_processing(format, str, ap);
	va_end(ap);
	free(str);
	return (length);
}

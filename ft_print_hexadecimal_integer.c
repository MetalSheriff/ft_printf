/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal_integer.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:27:57 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/24 18:27:57 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexadecimal_integer(t_struct *str, va_list ap, char letter)
{
	char				*buffer;
	unsigned long long	pointer;
	int					length;

	pointer = (unsigned int)va_arg(ap, unsigned int);
	buffer = ft_local_itoa_base(pointer, 16, letter);
	length = ft_strlen(buffer);
	if (pointer == 0 && str->precision >= 0)
		length = 0;
	ft_print_converter(str, length);
	if (str->minus == 1)
		ft_print_left_alignment(str, buffer, length);
	else
		ft_print_right_alignment(str, buffer, length);
	free(buffer);
}

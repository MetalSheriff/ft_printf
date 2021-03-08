/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:07:29 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/24 20:37:07 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_reset(t_struct *str)
{
	str->null_pointer = 0;
	str->print = 0;
	str->position = 0;
	str->minus = 0;
	str->zero = 0;
	str->width = 0;
	str->precision = -1;
	str->width_to_fill = 0;
	str->precision_to_fill = 0;
	str->flag_minus = 0;
	str->pointer = 0;
}

void	ft_flags_reset(t_struct *str)
{
	str->null_pointer = 0;
	str->minus = 0;
	str->zero = 0;
	str->width = 0;
	str->precision = -1;
	str->width_to_fill = 0;
	str->precision_to_fill = 0;
	str->flag_minus = 0;
	str->pointer = 0;
}

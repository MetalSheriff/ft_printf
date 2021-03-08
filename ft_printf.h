/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:16:51 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/26 13:35:44 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_struct
{
	int			print;
	int			position;
	int			minus;
	int			zero;
	int			width;
	int			precision;
	int			flag_minus;
	int			precision_to_fill;
	int			width_to_fill;
	int			null_pointer;
	int			pointer;
}					t_struct;

int					ft_printf(const char *format, ...);
int					ft_input_data_processing(const char *format,
t_struct *str, va_list ap);
void				ft_parsing_modifiers(const char *format, t_struct *str,
va_list ap);
void				ft_parsing_types(const char *format, t_struct *str,
va_list ap);
void				ft_struct_reset(t_struct *str);
void				ft_flags_reset(t_struct *str);
char				*ft_local_itoa_base(unsigned long long value, int base,
char letter);
void				ft_print_converter(t_struct *str, int length);
void				ft_print_left_alignment(t_struct *str, char *buffer,
int length);
void				ft_print_right_alignment(t_struct *str, char *buffer,
int length);
void				ft_print_integer(t_struct *str, va_list ap);
void				ft_print_unsigned_integer(t_struct *str, va_list ap);
void				ft_print_hexadecimal_integer(t_struct *str, va_list ap,
char letter);
void				ft_print_character(t_struct *str, va_list ap);
void				ft_print_string(t_struct *str, va_list ap);
void				ft_print_pointer(t_struct *str, va_list ap);
void				ft_character_converter(t_struct *str);
void				ft_print_percent(t_struct *str, char percent);

#endif

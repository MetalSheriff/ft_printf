/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 10:54:33 by ypeckled          #+#    #+#             */
/*   Updated: 2021/01/25 12:51:10 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	neg;
	long	nbr;

	neg = 1;
	nbr = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((nbr > FT_LIM || (nbr == FT_LIM && (*str - 48) > 7)) && neg == 1)
			return (-1);
		if ((nbr > FT_LIM || (nbr == FT_LIM && (*str - 48) > 7)) && neg == -1)
			return (0);
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return ((int)(nbr * neg));
}

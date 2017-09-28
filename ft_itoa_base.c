/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:30:19 by opariy            #+#    #+#             */
/*   Updated: 2017/07/11 16:30:21 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		f(intmax_t value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (value <= -base || value >= base)
		f(value / base, base, str, i);
	if ((value % base) < 0)
		str[*i] = tmp[-(value % base)];
	else
		str[*i] = tmp[value % base];
	(*i)++;
}

char		*ft_itoa_base(intmax_t value, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	if (base == 10 && value < 0)
		str[i++] = '-';
	if (value == 0)
		return ("0");
	if (value == 1)
		return ("1");
	f(value, base, str, &i);
	str[i] = '\0';
	return (str);
}

void		f_unintmax(uintmax_t value, unsigned int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (value >= base)
		f(value / base, base, str, i);
	str[*i] = tmp[value % base];
	(*i)++;
}

char		*ft_itoa_base_unintmax(uintmax_t value, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	if (value == 0)
		return ("0");
	if (value == 1)
		return ("1");
	f_unintmax(value, base, str, &i);
	str[i] = '\0';
	return (str);
}

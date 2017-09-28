/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 18:56:27 by opariy            #+#    #+#             */
/*   Updated: 2017/07/23 18:56:30 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parse_dd(t_instruction *instr, va_list ap)
{
	long int a;

	if (instr->spec == 'D')
	{
		a = va_arg(ap, long int);
		if (a < 0)
		{
			instr->minus = 1;
			instr->space = 0;
			instr->plus = 0;
			a = a * (-1);
		}
		if ((a == 0) && (instr->precision == 0))
		{
			instr->str = ft_strnew(0);
			instr->str = ft_strdup("\0");
		}
		else
			instr->str = ft_itoa_base(a, 10);
		if (instr->str[0] == '-')
			instr->str = ft_strsub(instr->str, 1, ft_strlen(instr->str));
	}
}

intmax_t	helper_f(t_instruction *instr, intmax_t a)
{
	instr->minus = 1;
	instr->space = 0;
	instr->plus = 0;
	a = -a;
	return (a);
}

void		helper_f2(t_instruction *instr, intmax_t a)
{
	if ((instr->type == ll) || (instr->type == hh))
		instr->str = ft_itoa_base_unintmax(a, 10);
	else
		instr->str = ft_itoa_base(a, 10);
	if (instr->str[0] == '-')
		instr->str = ft_strsub(instr->str, 1, ft_strlen(instr->str));
}

void		helper_f3(t_instruction *instr, intmax_t a)
{
	if (a < 0)
		a = helper_f(instr, a);
	if ((a == 0) && (instr->precision == 0))
		instr->str = ft_strdup("\0");
	else
		helper_f2(instr, a);
}

void		ft_parse_i_d(t_instruction *instr, va_list ap)
{
	intmax_t a;

	if ((instr->spec == 'd') || (instr->spec == 'i'))
	{
		if (instr->type == hh)
			a = (signed char)va_arg(ap, int);
		else if (instr->type == h)
			a = (short int)va_arg(ap, int);
		else if (instr->type == l)
			a = va_arg(ap, long int);
		else if (instr->type == ll)
			a = va_arg(ap, long long int);
		else if (instr->type == j)
			a = va_arg(ap, intmax_t);
		else if (instr->type == z)
			a = va_arg(ap, size_t);
		else if (instr->type == t)
			a = va_arg(ap, ptrdiff_t);
		else
			a = va_arg(ap, int);
		helper_f3(instr, a);
	}
}

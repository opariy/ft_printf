/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_x_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 18:53:52 by opariy            #+#    #+#             */
/*   Updated: 2017/07/23 18:53:53 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parse_b(t_instruction *instr, va_list ap)
{
	uintmax_t a;

	if (instr->spec == 'b')
	{
		if (instr->type == hh)
			a = (unsigned char)va_arg(ap, unsigned int);
		else if (instr->type == h)
			a = (unsigned short int)va_arg(ap, unsigned int);
		else if (instr->type == l)
			a = va_arg(ap, unsigned long int);
		else if (instr->type == ll)
			a = va_arg(ap, unsigned long long int);
		else if (instr->type == j)
			a = va_arg(ap, uintmax_t);
		else if (instr->type == z)
			a = va_arg(ap, size_t);
		else if (instr->type == t)
			a = va_arg(ap, ptrdiff_t);
		else
			a = va_arg(ap, unsigned int);
		instr->str = ft_itoa_base_unintmax(a, 2);
	}
}

void		ft_parse_bb(t_instruction *instr, va_list ap)
{
	unsigned long int a;

	if (instr->spec == 'B')
	{
		a = va_arg(ap, unsigned long int);
		instr->str = ft_itoa_base_unintmax(a, 2);
	}
}

void		ft_parse_xx(t_instruction *instr, va_list ap)
{
	unsigned long int a;

	if (instr->spec == 'X')
	{
		if (instr->type == hh)
			a = (unsigned char)va_arg(ap, int);
		else if (instr->type == h)
			a = (unsigned short int)va_arg(ap, int);
		else if (instr->type == l)
			a = va_arg(ap, unsigned long int);
		else if (instr->type == ll)
			a = va_arg(ap, unsigned long long int);
		else if (instr->type == j)
			a = va_arg(ap, uintmax_t);
		else if (instr->type == z)
			a = va_arg(ap, size_t);
		else if (instr->type == t)
			a = va_arg(ap, ptrdiff_t);
		else
			a = va_arg(ap, unsigned int);
		instr->str = ((a == 0) && (instr->precision == 0)) ? ft_strdup("\0") :
				ft_strcapitalize(ft_itoa_base_unintmax(a, 16));
		instr->sharp = (a == 0) ? 0 : instr->sharp;
	}
}

void		helper_f4(uintmax_t a, t_instruction *instr)
{
	if ((a == 0) && (instr->precision == 0))
		instr->str = ft_strdup("\0");
	else
		instr->str = ft_itoa_base_unintmax(a, 16);
	instr->sharp = (a == 0) ? 0 : instr->sharp;
}

void		ft_parse_x(t_instruction *instr, va_list ap)
{
	uintmax_t a;

	if (instr->spec == 'x')
	{
		if (instr->type == hh)
			a = (unsigned char)va_arg(ap, int);
		else if (instr->type == h)
			a = (unsigned short int)va_arg(ap, int);
		else if (instr->type == l)
			a = va_arg(ap, unsigned long int);
		else if (instr->type == ll)
			a = va_arg(ap, unsigned long long int);
		else if (instr->type == j)
			a = va_arg(ap, uintmax_t);
		else if (instr->type == z)
			a = va_arg(ap, size_t);
		else if (instr->type == t)
			a = va_arg(ap, ptrdiff_t);
		else
			a = va_arg(ap, unsigned int);
		helper_f4(a, instr);
	}
}

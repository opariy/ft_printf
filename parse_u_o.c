/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_u_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 18:49:32 by opariy            #+#    #+#             */
/*   Updated: 2017/07/23 18:49:34 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		helper_f5(uintmax_t a, t_instruction *instr)
{
	if ((a == 0) && (instr->precision == 0))
		instr->str = ft_strdup("\0");
	else if ((a == 0) && (instr->precision <= 0))
	{
		instr->str = ft_strnew(0);
		instr->str = ft_itoa_base_unintmax(a, 8);
		instr->sharp = 0;
	}
	else
		instr->str = ft_itoa_base_unintmax(a, 8);
}

void		ft_parse_o(t_instruction *instr, va_list ap)
{
	uintmax_t a;

	if (instr->spec == 'o')
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
		helper_f5(a, instr);
	}
}

void		ft_parse_oo(t_instruction *instr, va_list ap)
{
	uintmax_t a;

	if (instr->spec == 'O')
	{
		a = va_arg(ap, unsigned long int);
		if ((a == 0) && (instr->precision == 0))
			instr->str = ft_strdup("\0");
		else
		{
			instr->sharp = (a == 0) ? 0 : instr->sharp;
			instr->str = ft_itoa_base_unintmax(a, 8);
		}
	}
}

void		ft_parse_u(t_instruction *instr, va_list ap)
{
	uintmax_t a;

	if (instr->spec == 'u')
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
		if ((a == 0) && (instr->precision == 0))
			instr->str = ft_strdup("\0");
		else
			instr->str = ft_itoa_base_unintmax(a, 10);
	}
}

void		ft_parse_uu(t_instruction *instr, va_list ap)
{
	unsigned long int a;

	if (instr->spec == 'U')
	{
		a = va_arg(ap, unsigned long int);
		if ((a == 0) && (instr->precision == 0))
		{
			instr->str = ft_strnew(0);
			instr->str = ft_strdup("\0");
		}
		else
			instr->str = ft_itoa_base_unintmax(a, 10);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_s_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 18:38:13 by opariy            #+#    #+#             */
/*   Updated: 2017/07/23 18:38:15 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	weird_norm_fun(t_instruction *instr)
{
	instr->weird_flag = 1;
	instr->width -= 1;
	instr->length += 1;
}

void	ft_parse_c(t_instruction *i, va_list ap)
{
	int			a;

	if ((i->spec == 'c') || (i->spec == 'C'))
	{
		if (i->type == 3)
		{
			a = va_arg(ap, int);
			(a == 0) ? (weird_norm_fun(i)) : (i->str = ft_wchar((int)a));
		}
		else if (i->type == 0)
		{
			a = va_arg(ap, wint_t);
			if (a == 0)
				weird_norm_fun(i);
			else
				i->str = ft_char_to_string(a);
		}
		else
		{
			a = va_arg(ap, int);
			(a == 0) ? weird_norm_fun(i) : 0;
		}
	}
}

void	ft_parse_s(t_instruction *instr, va_list ap)
{
	wchar_t		*a;
	char		*str;

	if (instr->spec == 's')
	{
		if (instr->type == l)
		{
			a = va_arg(ap, wchar_t*);
			if (!a)
				instr->str = ft_strdup("(null)");
			else
				instr->str = ft_wstr(a, instr->precision);
		}
		else
		{
			str = va_arg(ap, char *);
			(instr->str) = (!str) ? ft_strdup("(null)") : ft_strdup(str);
		}
	}
}

void	ft_parse_ss(t_instruction *instr, va_list ap)
{
	int			*a;

	if (instr->spec == 'S')
	{
		a = va_arg(ap, int *);
		if ((char *)a == NULL)
			instr->str = ft_strdup("(null)");
		else
			instr->str = ft_wstr(a, instr->precision);
	}
}

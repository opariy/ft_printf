/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:56:16 by opariy            #+#    #+#             */
/*   Updated: 2017/07/23 19:56:18 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prec_helper(char c, t_instruction *i)
{
	int		len;

	len = 0;
	if ((c == 'o') || (c == 'O'))
	{
		if (i->precision >= 0)
			i->padding = 0;
		if (i->precision > (int)ft_strlen(i->str))
		{
			len = (int)ft_strlen(i->str);
			ft_add_c(i, i->precision - len - i->sharp, "0", 'f');
		}
	}
	else
	{
		if (i->precision >= 0)
			i->padding = 0;
		if (i->precision > (int)ft_strlen(i->str))
			ft_add_c(i, i->precision - (int)ft_strlen(i->str), "0", 'f');
	}
}

void	ft_change_precision(t_instruction *i)
{
	char c;

	c = i->spec;
	if ((ALL_NUM(c)))
	{
		prec_helper(c, i);
	}
	else if (c == 'p')
	{
		if (i->precision > (int)ft_strlen(i->str))
			ft_add_c(i, i->precision - (int)ft_strlen(i->str), "0", 'f');
		i->str = ft_strjoin("0x", i->str);
	}
	else if ((c == 's') || (c == 'S'))
	{
		if (i->precision < (int)ft_strlen(i->str))
		{
			i->str = ft_strsub(i->str, 0, i->precision);
		}
	}
}

void	helper_f6(t_instruction *i)
{
	if (i->width > (int)ft_strlen(i->str) && !(i->padding))
	{
		if (i->minus_flag == 1)
		{
			ft_add_c(i, i->width - (int)ft_strlen(i->str), " ", 'b');
		}
		else
			ft_add_c(i, i->width - (int)ft_strlen(i->str), " ", 'f');
	}
	else if (i->width > (int)ft_strlen(i->str) && (i->padding))
	{
		if (i->spec == 'p')
			ft_add_c(i, i->width - (int)ft_strlen(i->str), "0", 'b');
		else
		{
			if (i->minus_flag == 1)
				ft_add_c(i, i->width - (int)ft_strlen(i->str), "0", 'b');
			else
				ft_add_c(i, i->width - (int)ft_strlen(i->str), "0", 'f');
		}
	}
}

void	ft_change_width(t_instruction *instr)
{
	char	c;

	c = instr->spec;
	if ((instr->plus) && (!instr->padding))
	{
		ft_change_plus(instr);
		instr->plus = 0;
	}
	if ((instr->sharp) && (!instr->padding))
	{
		ft_change_sharp(instr);
		if (OCTAL_BASE(instr->spec))
			instr->width = instr->width - 1;
		else
			instr->width = instr->width - 2;
		instr->sharp = 0;
	}
	if (DEC_BASE(c) || DIFF_BASE(c) || (c == '%'))
		ft_change_width_num(instr);
	else
		helper_f6(instr);
}

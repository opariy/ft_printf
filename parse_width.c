/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:53:28 by opariy            #+#    #+#             */
/*   Updated: 2017/07/23 19:53:29 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_add_c(t_instruction *instr, int len, char *c, char pos)
{
	if (pos == 'f')
		while (len--)
			instr->str = ft_strjoin(c, instr->str);
	else
		while (len--)
			instr->str = ft_strjoin(instr->str, c);
}

void				ft_change_plus(t_instruction *i)
{
	i->str = (!i->minus && i->plus) ? ft_strjoin("+", i->str) : i->str;
}

void				width_norm(t_instruction *i)
{
	if (i->minus_flag)
	{
		if (DIFF_BASE(i->spec))
			if (i->sharp)
				i->width -= ((OCTAL_BASE(i->spec)) ? 1 : 2);
		ft_add_c(i, i->width - (int)ft_strlen(i->str) - i->plus
					- i->space, " ", 'b');
	}
	else
	{
		if (DIFF_BASE(i->spec))
			if (i->sharp)
				i->width -= ((OCTAL_BASE(i->spec)) ? 1 : 2);
		ft_add_c(i, i->width - (int)ft_strlen(i->str) - i->plus
					- i->space, " ", 'f');
	}
}

void				ft_change_width_num(t_instruction *i)
{
	if (i->width > (int)ft_strlen(i->str))
	{
		if (i->padding)
		{
			if (!i->minus_flag)
				if (DIFF_BASE(i->spec))
					if (i->sharp)
						i->width -= ((OCTAL_BASE(i->spec)) ? 1 : 2);
			ft_add_c(i, i->width - (int)ft_strlen(i->str)
						- i->plus - i->space - i->minus, "0", 'f');
		}
		else
			width_norm(i);
	}
}

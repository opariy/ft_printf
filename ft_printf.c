/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:33:08 by opariy            #+#    #+#             */
/*   Updated: 2017/06/29 14:33:10 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_special_chars(char c)
{
	if (ft_strchr(" .hljzt0123456789#-+", c))
		return (1);
	return (0);
}

int		get_instruction(char *str, t_instruction *instr)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_special_chars(str[i]))
			break ;
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	instr->str = ft_strsub(str, 0, (size_t)i + 1);
	return (i);
}

void	ft_initialize(t_instruction *instr)
{
	instr->precision = -1;
	instr->padding = 0;
	instr->minus = 0;
	instr->minus_flag = 0;
	instr->plus = 0;
	instr->type = def;
	instr->sharp = 0;
	instr->space = 0;
	instr->width = 0;
	instr->weird_flag = 0;
	instr->str = ft_strdup("\0");
}

void	ft_work_w_i(char *str, t_instruction *instr, const char *f, va_list ap)
{
	char	*per_sign;
	int		i;

	per_sign = ft_strchr(str, '%');
	if (!per_sign)
		ft_putstr_in(str, instr);
	else if (str < per_sign)
	{
		ft_putnstr(str, per_sign - str, instr);
		ft_work_w_i(per_sign, instr, f, ap);
	}
	else if (str == per_sign)
	{
		i = get_instruction(str + 1, instr);
		if (i != -1)
		{
			ft_parse_instruction(instr);
			ft_parse_spec(instr, ap);
			ft_deal_with_flags(instr);
			ft_initialize(instr);
			ft_work_w_i(str + i + 2, instr, f, ap);
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_instruction	*instr;

	va_start(ap, format);
	instr = (t_instruction *)malloc(sizeof(t_instruction));
	instr->precision = -1;
	instr->padding = 0;
	instr->minus = 0;
	instr->minus_flag = 0;
	instr->plus = 0;
	instr->type = def;
	instr->sharp = 0;
	instr->space = 0;
	instr->width = 0;
	instr->str = ft_strnew(0);
	instr->length = 0;
	instr->weird_flag = 0;
	instr->str = ft_strdup("\0");
	ft_work_w_i((char*)format, instr, format, ap);
	va_end(ap);
	return (instr->length);
}

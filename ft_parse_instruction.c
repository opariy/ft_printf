/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 13:53:45 by opariy            #+#    #+#             */
/*   Updated: 2017/07/05 13:53:46 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_size(char *str, int i, t_instruction *instr)
{
	while (str[i] && ft_strchr("hljzt", str[i]))
	{
		if (str[i] == 'h')
		{
			if ((ft_count_alpha(str, &i, 'h') % 2))
				instr->type = (instr->type <= h) ? h : instr->type;
			else
				instr->type = (instr->type <= hh) ? hh : instr->type;
		}
		if (str[i] == 'l')
		{
			if ((ft_count_alpha(str, &i, 'l') % 2))
				instr->type = (instr->type <= l) ? l : instr->type;
			else
				instr->type = (instr->type <= ll) ? ll : instr->type;
			i -= 1;
		}
		stupid_norm_function(instr, i, str);
		i++;
	}
	return (i);
}

int		ft_check_width(char *str, int i, t_instruction *instr)
{
	int		start;

	start = i;
	while (ft_isdigit(str[i]))
		i++;
	instr->width = ft_atoi(ft_strsub(str, start, i));
	return (i);
}

int		ft_check_precision(char *str, int i, t_instruction *instr)
{
	int		p;

	instr->precision = 0;
	if (ft_isdigit(str[i]))
	{
		while (str[i] == '0')
			i++;
		p = i;
		while (ft_isdigit(str[i]))
			i++;
		instr->precision = (p != i) ? ft_atoi(ft_strsub(str, p, i)) : 0;
	}
	return (i);
}

int		ft_check_for_flags(char letter, t_instruction *instr)
{
	if (letter == '0' && (instr->precision == -1) && (instr->minus_flag == 0))
		instr->padding = 1;
	else if (letter == '#' && DIFF_BASE(instr->spec))
		instr->sharp = 1;
	else if (letter == '+' && INT_NUM(instr->spec))
	{
		instr->plus = 1;
		instr->space = 0;
	}
	else if (letter == ' ' && instr->plus == 0)
		instr->space = 1;
	else if (letter == '-')
	{
		instr->minus_flag = 1;
		instr->padding = 0;
	}
	return (1);
}

void	ft_parse_instruction(t_instruction *instr)
{
	int		i;
	char	*str;

	str = ft_strdup(instr->str);
	instr->spec = str[ft_strlen(str) - 1];
	i = 0;
	while (str[i] && str[i] != instr->spec)
	{
		if ((str[i] == '0') || (str[i] == '#') || (str[i] == '+')
			|| (str[i] == ' ') || (str[i] == '-'))
			i += ft_check_for_flags(str[i], instr);
		else if (str[i] == '.')
			i = ft_check_precision(str, i + 1, instr);
		else if (ft_isdigit(str[i]) && str[i] != 48)
			i = ft_check_width(str, i, instr);
		else if (ft_strchr("hljzt", str[i]))
			i = ft_check_size(str, i, instr);
	}
}

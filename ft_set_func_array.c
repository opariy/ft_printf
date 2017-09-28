/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_func_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:12:35 by opariy            #+#    #+#             */
/*   Updated: 2017/07/08 12:12:37 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_change_sharp(t_instruction *instr)
{
	if (instr->sharp == 1)
	{
		if ((instr->spec == 'b') || (instr->spec == 'B'))
		{
			instr->str = ft_strjoin("0b", instr->str);
			instr->width += 2;
		}
		else if ((instr->spec == 'o') || (instr->spec == 'O'))
		{
			instr->width += 1;
			instr->str = ft_strjoin("0", instr->str);
		}
		else if (instr->spec == 'X')
		{
			instr->str = ft_strjoin("0X", instr->str);
			instr->width += 2;
		}
		else if (instr->spec == 'x')
		{
			instr->str = ft_strjoin("0x", instr->str);
			instr->width += 2;
		}
	}
}

void				ft_change_space(t_instruction *instr)
{
	if (!instr->minus && !instr->plus && instr->space && INT_NUM(instr->spec))
		instr->str = ft_strjoin(" ", instr->str);
	else
		instr->str = instr->str;
}

void				ft_change_minus(t_instruction *instr)
{
	if (instr->padding)
	{
		ft_change_width(instr);
		instr->width = 0;
	}
	instr->str = (instr->minus) ? ft_strjoin("-", instr->str) : instr->str;
}

t_ft_change_instrc	*ft_set_function_arr(void)
{
	t_ft_change_instrc	*func_arr;

	func_arr = (t_ft_change_instrc*)malloc(sizeof(t_ft_change_instrc*) * 8 + 1);
	func_arr[0] = ft_change_precision;
	func_arr[1] = ft_change_minus;
	func_arr[2] = ft_change_width;
	func_arr[3] = ft_change_sharp;
	func_arr[4] = ft_change_space;
	func_arr[5] = ft_change_plus;
	func_arr[6] = NULL;
	return (func_arr);
}

void				ft_deal_with_flags(t_instruction *instr)
{
	int					i;
	t_ft_change_instrc	*flag_arr;

	i = 0;
	flag_arr = ft_set_function_arr();
	while (flag_arr[i])
	{
		flag_arr[i](instr);
		i++;
	}
	ft_putstr_in(instr->str, instr);
	if (instr->weird_flag)
		write(1, "\0", 1);
}

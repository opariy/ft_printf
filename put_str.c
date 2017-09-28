/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 20:00:48 by opariy            #+#    #+#             */
/*   Updated: 2017/07/23 20:00:50 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_in(char const *s, t_instruction *instr)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			instr->length = instr->length + 1;
			ft_putchar(s[i]);
			i++;
		}
	}
}

void	ft_putnstr(char *str, unsigned long len, t_instruction *instr)
{
	unsigned long	i;

	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		instr->length = instr->length + 1;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_of_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:49:32 by opariy            #+#    #+#             */
/*   Updated: 2017/07/20 17:49:34 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_count_alpha(char *str, int *i, char c)
{
	int			counter;
	int			temp;

	temp = *i;
	counter = 0;
	while (str[temp] && (str[temp] == c || str[temp] == ' '))
	{
		if (str[temp] == c || str[temp] == ' ')
			(str[temp] == c) ? counter++ : 0;
		else
			break ;
		temp++;
	}
	*i = temp;
	return (counter);
}

char		*ft_strcapitalize(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		new[i] = (char)((str[i] >= 97 && str[i] <= 122) ? str[i] - 32 : str[i]);
		i++;
	}
	return (new);
}

void		stupid_norm_function(t_instruction *instr, int i, char *str)
{
	if (str[i] == 'j')
		instr->type = (instr->type <= j) ? j : instr->type;
	if (str[i] == 'z')
		instr->type = (instr->type <= z) ? z : instr->type;
	if (str[i] == 't')
		instr->type = (instr->type <= t) ? t : instr->type;
}

char		*ft_char_to_string(int c)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(int) + 1);
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);
}

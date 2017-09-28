/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:29:52 by opariy            #+#    #+#             */
/*   Updated: 2017/07/06 18:29:53 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_parse_p(t_instruction *instr, va_list ap)
{
	void *a;

	if (instr->spec == 'p')
	{
		a = va_arg(ap, void *);
		if ((a == 0) && (instr->precision == 0))
		{
			instr->str = ft_strnew(0);
			instr->str = ft_strdup("\0");
		}
		else
			instr->str = ft_itoa_base_unintmax((uintmax_t)a, 16);
	}
}

void				ft_parse_others(t_instruction *instr, va_list ap)
{
	(void)ap;
	if (instr->spec == '%')
		instr->str = "%";
	else if (!ALL_SPEC(instr->spec))
		instr->str[0] = instr->spec;
}

t_ft_parse_spec		*ft_set_function_spec(void)
{
	t_ft_parse_spec *spec_func;

	spec_func = (t_ft_parse_spec *)malloc(sizeof(t_ft_parse_spec*) * 15 + 1);
	spec_func[1] = ft_parse_i_d;
	spec_func[2] = ft_parse_dd;
	spec_func[8] = ft_parse_u;
	spec_func[3] = ft_parse_uu;
	spec_func[4] = ft_parse_o;
	spec_func[5] = ft_parse_oo;
	spec_func[6] = ft_parse_x;
	spec_func[7] = ft_parse_xx;
	spec_func[0] = ft_parse_b;
	spec_func[9] = ft_parse_bb;
	spec_func[10] = ft_parse_c;
	spec_func[11] = ft_parse_s;
	spec_func[12] = ft_parse_ss;
	spec_func[13] = ft_parse_p;
	spec_func[14] = ft_parse_others;
	spec_func[15] = NULL;
	return (spec_func);
}

void				ft_parse_spec(t_instruction *instr, va_list ap)
{
	int				i;
	t_ft_parse_spec *spec_func;

	i = 1;
	spec_func = ft_set_function_spec();
	instr->str = (char*)ft_memalloc(1);
	while (spec_func[i] != NULL)
	{
		spec_func[i](instr, ap);
		i++;
	}
}

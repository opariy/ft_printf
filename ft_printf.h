/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:18:52 by opariy            #+#    #+#             */
/*   Updated: 2017/06/29 14:18:55 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <wctype.h>

# define ALL_SPEC(c) (ALL_NUM(c) || OTHER(c) || CHAR_STR(c) ? 1 : 0)
# define ALL_NUM(c) (DEC_BASE(c) || DIFF_BASE(c) ? 1 : 0)

# define INT_NUM(c) ((c == 'd') || (c == 'D') || (c == 'i') ? 1 : 0)
# define UINT_NUM(c) ((c == 'u')  || (c == 'U') ? 1 : 0)
# define DEC_BASE(c) (INT_NUM(c) || UINT_NUM(c) ? 1 : 0)

# define DIFF_BASE(c) (OCTAL_BASE(c) || HEX_BASE(c) || BI_BASE(c) ? 1 : 0)
# define OCTAL_BASE(c) ((c == 'O') || (c == 'o') ? 1 : 0)
# define HEX_BASE(c) ((c == 'x') || (c == 'X') ? 1 : 0)
# define BI_BASE(c) ((c == 'b') || (c == 'B') ? 1 : 0)

# define STR_TYPE(c) ((c == 's') || (c == 'S') ? 1 : 0)
# define CHAR_TYPE(c) ((c == 'c')  || (c == 'C') ? 1 : 0)
# define CHAR_STR(c) STR_TYPE(c) || CHAR_TYPE(c)

# define OTHER(c) ((c == '%') || (c == 'p') ? 1 : 0)

typedef struct	s_instruction
{
	char		*str;
	int			width;
	int			precision;
	int			sharp;
	int			padding;
	int			minus;
	int			plus;
	int			space;
	int			length;
	char		spec;
	int			minus_flag;
	int			weird_flag;

	enum		e_typecast {
		def = 0,
		hh = 1,
		h = 2,
		l = 3,
		ll = 4,
		j = 5,
		z = 6,
		t = 7
	}			type;

}				t_instruction;

typedef void	(*t_ft_change_instrc)(t_instruction *instr);
typedef void	(*t_ft_parse_spec)(t_instruction *instr, va_list ap);

void			ft_parse_instruction(t_instruction *instr);
int				ft_printf(const char *format, ...);
void			ft_parse_spec(t_instruction *instr, va_list ap);
char			*ft_itoa_base(intmax_t value, int base);
char			*ft_strcapitalize(char *str);
void			ft_deal_with_flags(t_instruction *instr);
void			ft_putstr_in(char const *s, t_instruction *instr);
char			*ft_itoa_base_unintmax(uintmax_t value, int base);
int				ft_count_alpha(char *str, int *i, char c);
char			*ft_strcapitalize(char *str);
void			stupid_norm_function(t_instruction *instr, int i, char *str);
void			ft_parse_c(t_instruction *instr, va_list ap);
void			ft_parse_s(t_instruction *instr, va_list ap);
void			ft_parse_ss(t_instruction *instr, va_list ap);
char			*ft_wstr(int *arr, int precision);
char			*ft_wchar(int wchar);
char			*ft_char_to_string(int c);
void			ft_parse_uu(t_instruction *instr, va_list ap);
void			ft_parse_u(t_instruction *instr, va_list ap);
void			ft_parse_oo(t_instruction *instr, va_list ap);
void			ft_parse_o(t_instruction *instr, va_list ap);
void			ft_parse_b(t_instruction *instr, va_list ap);
void			ft_parse_bb(t_instruction *instr, va_list ap);
void			ft_parse_xx(t_instruction *instr, va_list ap);
void			ft_parse_x(t_instruction *instr, va_list ap);
void			ft_parse_dd(t_instruction *instr, va_list ap);
void			ft_parse_i_d(t_instruction *instr, va_list ap);
void			ft_add_c(t_instruction *i, int len, char *c, char pos);
void			ft_change_plus(t_instruction *i);
void			width_norm(t_instruction *i);
void			ft_change_width_num(t_instruction *i);
void			ft_change_width(t_instruction *instr);
void			helper_f6(t_instruction *i);
void			ft_change_precision(t_instruction *i);
void			prec_helper(char c, t_instruction *i);
void			ft_putstr_in(char const *s, t_instruction *instr);
void			ft_putnstr(char *str, unsigned long len, t_instruction *instr);
void			ft_change_sharp(t_instruction *instr);

#endif

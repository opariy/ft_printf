/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_char_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 18:45:23 by opariy            #+#    #+#             */
/*   Updated: 2017/07/23 18:45:24 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_wchar(int wchar)
{
	unsigned char	two_bytes[3];
	unsigned char	three_bytes[4];

	if (wchar < 128)
		return (ft_char_to_string(wchar));
	if (wchar > 127 && wchar < 2048)
	{
		two_bytes[0] = (wchar >> 6) + 192;
		two_bytes[1] = (wchar << 2);
		two_bytes[1] = (two_bytes[1] >> 2) + 128;
		two_bytes[2] = '\0';
		return (ft_strdup((char*)two_bytes));
	}
	three_bytes[0] = (wchar >> 12) + 224;
	three_bytes[1] = (wchar >> 6);
	three_bytes[1] = (three_bytes[1] << 2);
	three_bytes[1] = (three_bytes[1] >> 2) + 128;
	three_bytes[2] = wchar << 2;
	three_bytes[2] = (three_bytes[2] >> 2) + 128;
	three_bytes[3] = '\0';
	return (ft_strdup((char*)three_bytes));
}

char		*ft_wstr(int *arr, int precision)
{
	int			len;
	char		*symb;
	char		*str;
	size_t		counter;

	counter = -1;
	len = 0;
	str = ft_strdup("");
	while (arr[++counter])
	{
		symb = ft_wchar(arr[counter]);
		if (precision > 0)
		{
			len += ft_strlen(symb);
			if (len <= precision)
				str = ft_strjoin(str, symb);
		}
		else
			str = ft_strcat(str, symb);
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

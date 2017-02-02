/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:15:14 by kbagot            #+#    #+#             */
/*   Updated: 2017/02/02 21:13:24 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *restrict format, ...)
{
	int		i;
	int 	j;
	va_list	ap;
	int		pcharc;
	s_prt	*prt;

	pcharc = 0;
	i = 0;
	va_start(ap, format);
	prt = (s_prt*)malloc(sizeof(s_prt));
	prt->returnvalue = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = i + 1;
			if (format[j] == '\0')
				return (0);
			if (ft_strchr("sSpdiDoOuUxXcC%", format[j]) == NULL)
			{
				while ((ft_strchr("sSpdiDoOuUxXcC%", format[j])) == NULL && format[j])
					if ((ft_strchr("%#0-+ hljz.123456789", format[j++])) == NULL)
						return (0);
				if ((ft_strchr("sSpdiDoOuUxXcC%", format[j])) == NULL)
					return (0);
				prt->prt = ft_strsub(&format[i], 1, j - i);
			//	printf("check specif stock :%s\n", prt->prt);
				make_specifier(ap, prt);
				i = j + 1;
			}
			else
			{
				prt->prt = ft_strsub(&format[i], 1, 1);
			//	printf("check specif stock :%s\n", prt->prt);
				make_specifier(ap, prt);
				i += 2;
			}
		}
		else
		{
			ft_putchar(format[i++]);
			pcharc++;
		}
	}
	va_end(ap);
	return (prt->returnvalue + pcharc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:15:14 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/24 18:46:48 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printf(const char *restrict format, ...)
{
	int		i;
	int 	j;
	va_list	ap;
	s_prt	*prt;

	i = 0;
	va_start(ap, format);
	prt = (s_prt*)malloc(sizeof(s_prt));
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = i + 1;
			if (ft_strchr("sSpdiDoOuUxXcC%", format[j]) == NULL)
			{
				while ((ft_strchr("sSpdiDoOuUxXcC%", format[j])) == NULL && format[j])
				{
					if ((ft_strchr("%#0-+ hljz.123456789", format[j])) == NULL)
					{
						write(1, "error subspecifiers\n", 20);
						exit (0);
					}
					j++;
				}
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
			ft_putchar(format[i]);
			i++;
		}
	}
//	printf("%s", format);
//	printf("%d", va_arg(ap, int));
//	printf("%s", va_arg(ap, char*));
	va_end(ap);
}

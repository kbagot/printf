/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:57:33 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/27 18:10:09 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void prt_modifier(s_prt *prt, char *new)
{
	ft_strdel(&prt->spec);
	prt->spec = new;
	new = NULL;
}

static void	init_flag(s_flag *flag, s_prt *prt)
{
	int j;

	j = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->hash = 0;
	flag->space = 0;
	flag->width = 0;
	flag->precision = 0;
	prt->speclen = (int)ft_strlen(prt->spec);
	while (ft_strchr(" -+#0", prt->prt[j]))
	{
		if (prt->prt[j] == '#')
			flag->hash = 1;
		if (prt->prt[j] == ' ')
			flag->space = 1;
		if (prt->prt[j] == '-')
			flag->minus = 1;
		if (prt->prt[j] == '+')
			flag->plus = 1;
		if (prt->prt[j] == '0')
			flag->zero = 1;
		j++;
	}
	if (prt->prt[j] == '.' || ft_strchr("0123456789", prt->prt[j]))
		{
			if (prt->prt[j] == '.')
				flag->precision = ft_atoi(&prt->prt[j + 1]);
			else
				flag->width = ft_atoi(&prt->prt[j]);
	//		printf("WIDTH : %d\n PRECISION : %d\n", flag->width, flag->precision);
		}
	while (ft_strchr(".0123456789", prt->prt[j]))
		j++;
	while (ft_strchr("hljz", prt->prt[j]))
	{

		j++;
	}
}

void	add_prt(s_prt *prt, int i)
{
	s_flag	*flag;
	int		j;

	j = 0;
	flag = (s_flag*)malloc(sizeof(s_flag));
	if (ft_strchr("cCsSuUdDioOxXp%", prt->prt[j]))
		ft_putstr(prt->spec);
	else
	{
		if (ft_strchr("cCsSuUdixXpoO%", prt->prt[i]))
		{
			init_flag(flag, prt);
	//		if ()
			if (flag->hash == 1 && (ft_strchr("oOxX", prt->prt[i])))
				prt_modifier(prt, ft_strjoin("0", prt->spec));
			if (ft_strchr("p", prt->prt[i]) == NULL && flag->precision > prt->speclen)
			{
				while ((flag->precision - prt->speclen) > 0)
				{
					prt_modifier(prt, ft_strjoin("0", prt->spec));
					flag->precision--;
				}
			}
			if (flag->width > prt->speclen)
			{
				while ((flag->width - prt->speclen) > 0)
				{
					if (flag->minus == 1)	
						prt_modifier(prt, ft_strjoin(prt->spec, " "));
					else
						prt_modifier(prt, ft_strjoin(" ", prt->spec));
					flag->width--;
				}
			}
			else if (flag->space == 1 && (prt->spec[0] != '-' || prt->spec[0] != '+') && ft_strchr("d%", prt->prt[i]) == NULL)
					prt_modifier(prt, ft_strjoin(" ", prt->spec));
			if (flag->plus == 1 && (ft_strchr("di", prt->prt[i])) && prt->spec[0] != '-')
				prt_modifier(prt, ft_strjoin("+", prt->spec));
			ft_putstr(prt->spec);
		}
/*		if (ft_strchr("duxXipoO", prt->prt[i]) == NULL)
		{
			j = init_flag(flag, prt);
			if (flag->width > prt->speclen)
			{
				while ((flag->width - prt->speclen) > 0)
				{
					if (flag->minus == 1)	
						prt_modifier(prt, ft_strjoin(prt->spec, " "));
					else
						prt_modifier(prt, ft_strjoin(" ", prt->spec));
					flag->width--;
				}
			}
			ft_putstr(prt->spec);
		}*/
	}
	prt->returnvalue += ft_strlen(prt->spec);
	free(prt->spec);
	prt->spec = NULL;
}

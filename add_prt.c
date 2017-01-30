/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:57:33 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/30 20:21:01 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void prt_modifier(s_prt *prt, char *new)
{
	ft_strdel(&prt->spec);
	prt->spec = new;
	new = NULL;
}

void	init_flag(s_flag *flag, s_prt *prt)
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
	flag->l = 0;
	flag->h = 0;
	flag->j = 0;
	flag->z = 0;
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
	//clean maybe it's  shit  !!
	if (flag->minus == 1 && flag->zero == 1)
		flag->zero = 0;
	if (flag->plus == 1 && flag->space == 1)
		flag->space = 0;
	if (prt->prt[j] == '.' || ft_strchr("0123456789", prt->prt[j]))
		{
			if (ft_strchr("0123456789", prt->prt[j]))
				flag->width = ft_atoi(&prt->prt[j]);
			while (ft_strchr("0123456789", prt->prt[j]))
				j++;
			if (prt->prt[j] == '.' && ft_strchr("0123456789", prt->prt[j + 1]))
				flag->precision = ft_atoi(&prt->prt[j + 1]);
	//		printf("WIDTH : %d\n PRECISION : %d\n", flag->width, flag->precision);
		}
	while (ft_strchr(".0123456789", prt->prt[j]))
		j++;
	while (ft_strchr("hljz", prt->prt[j]))
	{
		if (prt->prt[j] == 'l')
			flag->l++;
		if (prt->prt[j] == 'h')
			flag->h++;
		if (prt->prt[j] == 'j')
			flag->j++;
		if (prt->prt[j] == 'z')
			flag->h++;
		j++;
	}
}

static void	hash_mod(s_prt *prt)
{
	if (prt->i == 'x' || prt->i == 'X')
	{
			prt_modifier(prt, ft_strjoin(&prt->prt[ft_strlen(prt->prt) - 1], 
						prt->spec));
			prt_modifier(prt, ft_strjoin("0", prt->spec));
	}
	else
		prt_modifier(prt, ft_strjoin("0", prt->spec));
}

static void	precision_mod(s_flag *flag, s_prt *prt)
{
	prt->speclen = (int)ft_strlen(prt->spec);
	if (prt->i == 's')
	{
	//printf("||||%s|||||\n", prt->spec);
		prt->spec[flag->precision] = '\0';
	//	printf("|||[%s]||||\n", prt->spec);
	}
	else if (flag->precision > prt->speclen)
		while ((flag->precision - prt->speclen) > 0)
		{
			prt_modifier(prt, ft_strjoin("0", prt->spec));
			flag->precision--;
		}
}

static void	width_mod(s_flag *flag, s_prt *prt)
{
	char	*tmp;

	tmp = ft_strnew(1);
	prt->speclen = (int)ft_strlen(prt->spec);
	while ((flag->width - prt->speclen) > 0)
	{
		if (flag->zero == 1)
			tmp[0] = 48;
		else
			tmp[0] = 32;
		if (flag->minus == 1)
			prt_modifier(prt, ft_strjoin(prt->spec, tmp));
		else
			prt_modifier(prt, ft_strjoin(tmp, prt->spec));
		flag->width--;
	}
}

void		add_prt(s_prt *prt, s_flag *flag)
{
	if (ft_strchr("cCsSuUdDioOxXp%", prt->prt[0]))
		ft_putstr(prt->spec);
	else
	{
		if (ft_strchr("cCsSuUdixXpoO%", prt->i))
		{
			if (ft_strchr("p", prt->i) == NULL && flag->precision != 0)
				precision_mod(flag, prt);
			if (flag->space == 1 && (prt->spec[0] != '-' && prt->spec[0] != '+') 
					&& ft_strchr("%", prt->i) == NULL)
				prt_modifier(prt, ft_strjoin(" ", prt->spec));
			if (flag->hash == 1 && (ft_strchr("oOxX", prt->i)) && prt->spec[0] != '0')
				hash_mod(prt);
			if (flag->width > prt->speclen)
				width_mod(flag, prt);
			if (flag->plus == 1 && (ft_strchr("di", prt->i)) && prt->spec[0] != '-')
				prt_modifier(prt, ft_strjoin("+", prt->spec));
			ft_putstr(prt->spec);
		}
	}
	prt->returnvalue += ft_strlen(prt->spec);
	free(prt->spec);
	prt->spec = NULL;
}

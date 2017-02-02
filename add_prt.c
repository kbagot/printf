/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:57:33 by kbagot            #+#    #+#             */
/*   Updated: 2017/02/02 21:13:15 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void prt_modifier(s_prt *prt, char *new)
{
	ft_strdel(&prt->spec);
	prt->spec = new;
	new = NULL;
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
	int lol;

	lol = 0;
	if (prt->spec[0] == '-' || prt->spec[0] == '+')
	{
		lol = prt->spec[0];
		prt->spec[0] = '0';
	}
	prt->speclen = (int)ft_strlen(prt->spec);
	if (flag->precision == 0 && ft_atoi(prt->spec) == 0)
	{
			prt->spec[0] = '\0';
	}
	else if (prt->i == 's')
		prt->spec[flag->precision] = '\0';
	else if (flag->precision > prt->speclen)
		while ((flag->precision - prt->speclen) > 0)
		{
			prt_modifier(prt, ft_strjoin("0", prt->spec));
			flag->precision--;
		}
	if (lol == 45)
		prt_modifier(prt, ft_strjoin("-", prt->spec));
	if (lol == 43)
		prt_modifier(prt, ft_strjoin("+", prt->spec));
}

static void	width_mod(s_flag *flag, s_prt *prt)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(1);
	tmp[0] = 32;
	prt->speclen = (int)ft_strlen(prt->spec);
	if (flag->hash == 1 && flag->zero == 1)
		prt->spec[1] = '0';
	while ((flag->width - prt->speclen) > 0)
	{
		if (flag->zero == 1)
			tmp[0] = 48;
		if (flag->minus == 1)
			prt_modifier(prt, ft_strjoin(prt->spec, tmp));
		else
			prt_modifier(prt, ft_strjoin(tmp, prt->spec));
		flag->width--;
	}
	if (prt->spec[0] == '0')
	{
		while (prt->spec[i] == '0' && prt->spec[i])
			i++;
		if (prt->spec[i] == '+' || prt->spec[i] == '-')
		{
			prt->spec[0] = prt->spec[i];
			prt->spec[i] = '0';
		}
	}
	if (flag->hash == 1 && flag->zero == 1)
		prt->spec[1] = prt->i;
}

void		add_prt(s_prt *prt, s_flag *flag)
{
	if (flag->hash == 1 && flag->precision == 0 && ft_atoi(prt->spec) == 0 && ft_strchr("oO", prt->i))
		flag->precision = -1;
	if (ft_strchr("cCsSuUdDioOxXp%", prt->prt[0]))
		ft_putstr(prt->spec);
	else
	{
		if (ft_strchr("cCsSuUdixXpoO%", prt->i))
		{
			if (flag->hash == 1 && (ft_strchr("oOxX", prt->i)) && ft_atoi(prt->spec) != 0)
				hash_mod(prt);
			prt->speclen = (int)ft_strlen(prt->spec);
			if (flag->space == 1 && (prt->spec[0] != '-' && prt->spec[0] != '+') 
					&& ft_strchr("cu%", prt->i) == NULL && (prt->speclen >= flag->width && 
						prt->speclen >= flag->precision))
				prt_modifier(prt, ft_strjoin(" ", prt->spec));
			if (flag->plus == 1 && (ft_strchr("di", prt->i)) && prt->spec[0] != '-')
			{
				if (prt->spec[0] == 0)
					prt->spec[0] = '+';
				else
					prt_modifier(prt, ft_strjoin("+", prt->spec));
			}
			if (ft_strchr("cp%", prt->i) == NULL && flag->precision != -1)
				precision_mod(flag, prt);
			if (flag->width > prt->speclen)
				width_mod(flag, prt);
			ft_putstr(prt->spec);
		}
	}
	prt->returnvalue += ft_strlen(prt->spec);
	free(prt->spec);
	free(prt->prt);
	prt->spec = NULL;
}

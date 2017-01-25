/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:57:33 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/25 20:34:25 by kbagot           ###   ########.fr       */
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
}

void		add_prt(s_prt *prt, int i)
{
	s_flag *flag;
	int j;

	j = 0;
	flag = (s_flag*)malloc(sizeof(s_flag));
	if (ft_strchr("cCsSuUdDioOxXp%", prt->prt[j])) // tmp shit
		ft_putstr(prt->spec);
	else
	{
		init_flag(flag, prt);
		if (flag->hash == 1 && (ft_strchr("oOxX", prt->prt[i])))
			prt_modifier(prt, ft_strjoin("0", prt->spec));
		ft_putstr(prt->spec);
	}
	free(prt->spec);
	prt->spec = NULL;
}

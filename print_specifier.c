/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:25:40 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/28 19:22:01 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void stock_int(s_prt *prt, int c)
{
	prt->spec[prt->ispec] = c;
	prt->ispec++;
}

static void ft_putoctal(long long int n, s_prt *prt)
{
	if (n >= 8)
		ft_putoctal(n / 8, prt);
	stock_int(prt, (n % 8) + 48);
}

static void ft_puthexa(long long int n, char c, s_prt *prt)
{
	int ccase;
	int length;

	length = 0;
	if (c == 'X')
		ccase = 55;
	else
		ccase = 87;
	if (n >= 16)
		ft_puthexa(n / 16, c, prt);
	if (n % 16 <= 9)
		stock_int(prt, (n % 16) + 48);
	else
		stock_int(prt, (n % 16) + ccase);
}

static void ft_masterputnbr(s_prt *prt, va_list ap)
{
	void n;

	n = va_arg(ap, long long int);
	if (n < 0)
	{
		stock_int(prt, '-');
		n *= -1;
	}
	if (n >= 10)
		ft_masterputnbr(n / 10, prt);
	stock_int(prt, (n % 10) + 48);
}

static void	make_char_specif(va_list ap, s_prt *prt,s_flag *flag)
{
	if (ft_strchr("scCi", prt->i))
		if (prt->i == 's')
			prt->spec = ft_strdup(va_arg(ap, char*));
		if (prt->i == 'c' || prt->i == 'C')
		{
			prt->spec = ft_strnew(1);
			prt->spec[0] = va_arg(ap, int);
		}
		add_prt(prt, flag);
}
// |c(C=lc) s(S=ls)| |uU dD i| |oO xX| p
void		make_specifier(va_list ap, s_prt *prt)
{
	s_flag	*flag;
//specifier
	prt->ispec = 0;
	flag = (s_flag*)malloc(sizeof(s_flag));
	init_flag(flag, prt);
	prt->i = prt->prt[ft_strlen(prt->prt) - 1];
	if (prt->i == '%')
	{
//		prt->spec = ft_strdup("%");
		prt->spec = ft_strnew(1);
		prt->spec[0] = '%';
		add_prt(prt, flag);
	}
	else if (ft_strchr("duixXpoO", prt->i))
	{ // add fct clear&check type
		prt->spec = ft_strnew(20);//malloc for int type/char dned t shit
		if (prt->i == 'd' || prt->i == 'u'|| prt->i == 'i')
		{
			if (flag->l == 0)
				ft_masterputnbr(prt, ap);
			else if (flag->l == 1)
				ft_masterputnbr(prt, ap);
			else if (flag->l == 2)
				ft_masterputnbr(prt, ap);
//			printf("SALUT    }       %s ||||||||||\n", prt->spec);
		}
		if (prt->i == 'x' || prt->i == 'X' || prt->i == 'p')
		{
			if (prt->i == 'p')
			{
				ft_strcpy(prt->spec, "0x");
				prt->i += 2;
			}
			if (flag->l == 0)
				ft_puthexa(va_arg(ap, unsigned int), prt->i, prt);
			else if (flag->l == 1)
				ft_puthexa(va_arg(ap, unsigned long int), prt->i, prt);
			else if (flag->l == 2)
				ft_puthexa(va_arg(ap, unsigned long int), prt->i, prt);
		}
		if (prt->i == 'o' || prt->i == 'O')
		{
			if (flag->l == 0)
				ft_putoctal(va_arg(ap, unsigned int), prt);
			else if (flag->l == 1)
				ft_putoctal(va_arg(ap, unsigned long int), prt);
			else if (flag->l == 2)
				ft_putoctal(va_arg(ap, unsigned long long int), prt);
		}
		add_prt(prt, flag);
	} // cut it in 2 fct
	else
		make_char_specif(ap, prt, flag);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:25:40 by kbagot            #+#    #+#             */
/*   Updated: 2017/02/02 21:49:43 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void stock_int(s_prt *prt, int c)
{
	prt->spec[prt->ispec] = c;
	prt->ispec++;
}

static void ft_putoctal(unsigned long long int n, s_prt *prt)
{
	if (n >= 8)
		ft_putoctal(n / 8, prt);
	stock_int(prt, (n % 8) + 48);
}

static void ft_puthexa(unsigned long long int n, char c, s_prt *prt)
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

static void ft_masterputnbru(unsigned long long int n, s_prt *prt)
{
	if (n >= 10)
		ft_masterputnbru(n / 10, prt);
	stock_int(prt, (n % 10) + 48);
}

static void ft_masterputnbr(long long int n, s_prt *prt)
{
	unsigned long long int nb;

	nb = n;
	if (n < 0)
	{
		stock_int(prt, '-');
		nb *= -1;
	}
	if (nb >= 10)
		ft_masterputnbr(nb / 10, prt);
	stock_int(prt, (nb % 10) + 48);
}

static void	make_char_specif(va_list ap, s_prt *prt,s_flag *flag)
{
	char *tmp;

	tmp = NULL;
	if (ft_strchr("scCi", prt->i))
	{
		if (prt->i == 's')
		{
			tmp = va_arg(ap, char*);
			if (tmp != NULL)
			{
				prt->spec = ft_strdup(tmp);
				add_prt(prt, flag);
			}
			else
				ft_putstr("(null)");
		}
		if (prt->i == 'c' || prt->i == 'C')
		{
			prt->spec = ft_strnew(1);
			prt->spec[0] = va_arg(ap, int);
			if (prt->spec[0] == 0)
			{
				if (flag->width > 0)
					flag->width--;
				prt->returnvalue++;
				add_prt(prt, flag);
			}
			else
				add_prt(prt, flag);
		}
	}
}
// |c(C=lc) s(S=ls)| |uU dD i| |oO xX| p
void		make_specifier(va_list ap, s_prt *prt)
{
	s_flag	*flag;
	int n;

	n = 0;
//specifier
	prt->ispec = 0;
	flag = (s_flag*)malloc(sizeof(s_flag));
	init_sub_specif(flag, prt);
	prt->i = prt->prt[ft_strlen(prt->prt) - 1];
	if (prt->i == '%')
	{
//		prt->spec = ft_strdup("%");
		prt->spec = ft_strnew(1);
		prt->spec[0] = '%';
		add_prt(prt, flag);
	}
	else if (ft_strchr("DduUixXpoO", prt->i))
	{ // add fct clear&check type
		prt->spec = ft_strnew(20);//malloc for int type/char dned t shit
		if (prt->i == 'd' || prt->i == 'i')
		{
			if (flag->z == 1)
				ft_masterputnbr(va_arg(ap, size_t), prt);
			else if (flag->h == 1)
				ft_masterputnbr((short int)va_arg(ap, int), prt);
			else if (flag->h == 2)
				ft_masterputnbr((signed char)va_arg(ap, int), prt);
			else if (flag->l == 1)
				ft_masterputnbr(va_arg(ap, long int), prt);
			else if (flag->l == 2 || flag->j == 1)
				ft_masterputnbr(va_arg(ap, long long int), prt);
			else if (flag->l == 0)
				ft_masterputnbr(va_arg(ap, int), prt);
		}
		if (prt->i == 'u' || prt->i == 'U')
		{
			if (flag->h == 2)
				ft_masterputnbr((unsigned char)va_arg(ap, int), prt);
			else if (flag->l == 1 || prt->i == 'U')
				ft_masterputnbru(va_arg(ap, unsigned long int), prt);
			else if (flag->l == 2 || flag->j == 1)
				ft_masterputnbru(va_arg(ap, unsigned long long int), prt);
			else if (flag->h == 1)
				ft_masterputnbr((unsigned short int)va_arg(ap, int), prt);
			else if (flag->l == 0)
				ft_masterputnbr(va_arg(ap, unsigned int), prt);
		}
		if (prt->i == 'x' || prt->i == 'X' || prt->i == 'p')
		{
			if (prt->i == 'p')
			{
				ft_strcpy(prt->spec, "0x");
				prt->ispec += 2;
				ft_puthexa(va_arg(ap, unsigned long long int), prt->i, prt);
			}
			else if (flag->l == 1)
				ft_puthexa(va_arg(ap, unsigned long int), prt->i, prt);
			else if (flag->l == 2 || flag->j == 1)
				ft_puthexa(va_arg(ap, unsigned long long int), prt->i, prt);
			else if (flag->l == 0)
				ft_puthexa(va_arg(ap, unsigned int), prt->i, prt);
		}
		if (prt->i == 'o' || prt->i == 'O')
		{
			if (flag->l == 1 || prt->i == 'O')
				ft_putoctal(va_arg(ap, unsigned long int), prt);
			else if (flag->l == 2 || flag->j == 1)
				ft_putoctal(va_arg(ap, unsigned long long int), prt);
			else if (flag->l == 0)
				ft_putoctal(va_arg(ap, unsigned int), prt);
		}
		add_prt(prt, flag);
	} // cut it in 2 fct
	else
		make_char_specif(ap, prt, flag);
}

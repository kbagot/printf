/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:25:40 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/24 21:04:39 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void stock_int(s_prt *prt, int c)
{
	prt->spec[prt->i] = c;
	prt->i++;
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

// |c(C=lc) s(S=ls)| |uU dD i| |oO xX| p

int		make_specifier(va_list ap, s_prt *prt)
{
	int i;

//	printf("%s\n", prt->prt); // ICI chheck
	//flags
/*	if (prt->prt[i] == '+')
	{
		ft_putchar('+');
		i++;
	}
	if (prt->prt[i] == 'l' || prt->prt[i] == ' ')
	{
		if (prt->prt[i] == ' ')
		{
			ft_putchar(' ');
			while (prt->prt[i] == ' ')
				i++;
		}
		i++;
		if (prt->prt[i] == 'l')
			i++;
		if (prt->prt[i] == 'd' || prt->prt[i] == 'u'|| prt->prt[i] == 'i')
			ft_masterputnbr(va_arg(ap, long long int));
		if (prt->prt[i] == 'x' || prt->prt [i] == 'X')
			ft_puthexa(va_arg(ap, long long int), prt->prt[i]);
		return (0);
	}*/
//specifier
	prt->i = 0;
	i = ft_strlen(prt->prt) - 1;
	if (prt->prt[i] == '%')
		ft_putchar('%');
	if (ft_strchr("duixXpoO", prt->prt[i]))
	{ // add fct clear&check type
		prt->spec = ft_strnew(20);//malloc for int type/char dned t shit
		if (prt->prt[i] == 'd' || prt->prt[i] == 'u'|| prt->prt[i] == 'i')
			ft_masterputnbr(va_arg(ap, long long int), prt);
		if (prt->prt[i] == 'x' || prt->prt[i] == 'X' || prt->prt[i] == 'p')
		{
			if (prt->prt[i] == 'p')
			{
				ft_strcpy(prt->spec, "0x");
				prt->i += 2;
			}
			ft_puthexa(va_arg(ap, long long int), prt->prt[i], prt);
		}
		if (prt->prt[i] == 'o' || prt->prt[i] == 'O')
			ft_putoctal(va_arg(ap, long long int), prt);
		add_prt(prt);
	} // cut it in 2 fct
	if (ft_strchr("scC", prt->prt[i]))
	{ // add fct clear&check type
		if (prt->prt[i] == 's')
			prt->spec = ft_strdup(va_arg(ap, char*));
		if (prt->prt[i] == 'c' || prt->prt[i] == 'C')
		{
			prt->spec = ft_strnew(1);
			prt->spec[0] = va_arg(ap, int);
		}
		add_prt(prt);
	}
	return (0);
}

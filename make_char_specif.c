/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_char_specif.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:16:31 by kbagot            #+#    #+#             */
/*   Updated: 2017/02/09 18:37:50 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
/*
   char	*decimal_to_binary(int n)
   {
   int c;
   int d;
   int count;
   int c, d, count;
   char *pointer;

   count = 0;
   pointer = (char*)malloc(32+1);

   if ( pointer == NULL )
   exit(EXIT_FAILURE);

   for ( c = 31 ; c >= 0 ; c-- )
   {
   d = n >> c;

   if ( d & 1 )
 *(pointer+count) = 1 + '0';
 else
 *(pointer+count) = 0 + '0';

 count++;
 }
 *(pointer+count) = '\0';

 return  pointer;
 }
 */
static void	spec_s(t_prt *prt, t_flag *flag, va_list ap)
{
	char	*tmp;

	tmp = va_arg(ap, char*);
	if (tmp != NULL)
	{
		prt->spec = ft_strdup(tmp);
		add_prt(prt, flag);
	}
	else if (flag->precision != 0)
	{
		ft_putstr("(null)");
		prt->returnvalue += 6;
	}
	else
	{
		prt->spec = ft_strdup("\0");
		add_prt(prt, flag);
	}
}

static void	spec_c(t_prt *prt, t_flag *flag, va_list ap)
{
	prt->spec = ft_strnew(2);
	prt->spec[0] = va_arg(ap, int);
	if (prt->spec[0] == 0)
	{
		if (flag->width > 0)
			flag->width--;
		prt->returnvalue++;
		add_prt(prt, flag);
		ft_putchar(0);
	}
	else
		add_prt(prt, flag);
}

void		make_char_specif(va_list ap, t_prt *prt, t_flag *flag)
{
	int		dec;

	dec = 0;
	/*	if (ft_strchr("SC", prt->i))
		{

	 ** Bytes|    c4	     Format Output             |        Format Input         |
	 **   1  | 0xxxxxxx    c3                       | 00000000 00000000 0xxxxxxx  |
	 **   2  | 110yyyyy 10xxxxxx     c2             | 00000000 00000yyy yyxxxxxx  |
	 **   3  | 1110zzzz 10yyyyyy 10xxxxxx    c1     | 00000000 zzzzyyyy yyxxxxxx  |
	 ** 	 4  | 11110www 10zzzzzz 10yyyyyy 10xxxxxx  | 000wwwzz zzzzyyyy yyxxxxxx  |

	 prt->spec = ft_strnew(10);
	 ft_masterputnbru(va_arg(ap, unsigned int), prt);
	 prt->speclen = ft_strlen(prt->spec);
	 printf("%s\n {%d}", prt->spec, prt->speclen);
	 ft_puthexa(va_arg(ap, wchar_t), prt->i, prt);
	 printf("%s\n {%d}", prt->spec, prt->speclen);
	 }
	 else if (ft_strchr("sci", prt->i))
	 {*/
	if (prt->i == 's')
		spec_s(prt, flag, ap);
	if (prt->i == 'c')
		spec_c(prt, flag, ap);
	//	}
}

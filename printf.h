/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:53:04 by kbagot            #+#    #+#             */
/*   Updated: 2017/02/09 18:09:16 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <libft.h>
# include <wchar.h>
# include <limits.h>
# include <float.h>

typedef struct	s_prt
{
	int		index;
	int		ispec;
	int		i;
	char	*prt;
	char	*spec;
	int		speclen;
	int		returnvalue;
	int		wchar;
}				t_prt;

typedef struct	s_flag
{
	int		space;
	int		plus;
	int		hash;
	int		zero;
	int		minus;
	int		width;
	int		precision;
	int		l;
	int		h;
	int		j;
	int		z;
}				t_flag;

int				main(void);
int				ft_printf(const char *restrict format, ...);
void			make_specifier(va_list ap, t_prt *prt);
void			add_prt(t_prt *prt, t_flag *flag);
void			init_sub_specif(t_flag *flag, t_prt *prt);
void			add_length(t_flag *flag, t_prt *prt, va_list ap);
void			ft_masterputnbr(long long int n, t_prt *prt);
void			ft_masterputnbru(unsigned long long int n, t_prt *prt);
void			ft_puthexa(unsigned long long int n, char c, t_prt *prt);
void			ft_putoctal(unsigned long long int n, t_prt *prt);
void			make_char_specif(va_list ap, t_prt *prt, t_flag *flag);
void			width_mod(t_flag *flag, t_prt *prt);
void			precision_mod(t_flag *flag, t_prt *prt);
void			prt_modifier(t_prt *prt, char *new);

#endif

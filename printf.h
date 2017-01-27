/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:53:04 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/26 20:09:06 by kbagot           ###   ########.fr       */
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

typedef struct	t_prt
{
	int		i;
	char	*prt;
	char	*spec;
	int		speclen;
	int		returnvalue;
}				s_prt;

typedef struct t_flag
{
//flags
	int		space;
	int		plus;
	int		hash;
	int		zero;
	int		minus;
	int		width;
	int		precision;
}				s_flag;

int		main(void);
int		ft_printf(const char *restrict format, ...);
void	make_specifier(va_list ap, s_prt *prt);
void	add_prt(s_prt *prt, int i);

#endif

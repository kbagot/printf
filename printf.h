/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:53:04 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/24 21:04:43 by kbagot           ###   ########.fr       */
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
	int i;
	char *prt;
	char *spec;
}				s_prt;

int		main(void);
void	ft_printf(const char *restrict format, ...);
int		make_specifier(va_list ap, s_prt *prt);
void	add_prt(s_prt *prt);

#endif

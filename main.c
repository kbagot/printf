/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:24:35 by kbagot            #+#    #+#             */
/*   Updated: 2017/02/01 20:52:23 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(void)
{
 	int n;
	char *p;

	p = malloc(2);
	n = 42;
//	n = -200;
//	while (n <= 200){
//	printf("salut %s", NULL);
	ft_printf("moulitest %p\n", &p);
//	printf("moulitest %s\n", NULL);
//	printf
//		("%.20ld%+dSA%hd |%5.2s%%u%5ct%#x | %p\n", 9223372036854775807, -412, 32769, "lol", 116, n, p);
//	ft_printf
//		("%.20ld%+dSA%hd |%5.2s%%u%5ct%#x | %p\n", 9223372036854775807, -412, 33000, "lol", 116, n, p);
//		n++;}
//	while (n <= 200)
//	{
//		ft_printf("%  ", n);
//		printf("%d\n", n);
//		n++;
//	}
	return (0);
}

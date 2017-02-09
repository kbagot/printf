/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:24:35 by kbagot            #+#    #+#             */
/*   Updated: 2017/02/08 18:27:05 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "locale.h"

int		main(void)
{
//	int n;
//	char *p;
//	unsigned char c;
int c;

c = 0b00000010;
	setlocale(LC_ALL, "");
	printf("SAlut\n");
	printf("lol%lc\n", 255);
	printf("{%d}\n", c);
	while (c < 65800)
	{
	//	printf("%d | %x\n", c, c);
		c++;
	}
//	n = 42;
	c = 0xF0;
	write(1, &c, 1);
	c = 0x90;
	write(1, &c, 1);
	c = 0x80;
	write(1, &c, 1);
	c = 0x80;
	write(1, &c, 1);
	c = 0x0A;
	write(1, &c, 1);
	//	n = -200;
	//	while (n <= 200){
//		n = ft_printf("% o|% +o\n", 42, 42);
//		printf("%C\n", p);
	//	n = printf("% o|%+o", 42, 42);
	//	printf("%d\n", n);
	//	printf("%d\n", ft_printf("%15.4s\n", "I am 42"));
	//	printf("%d\n", printf("%15.4s\n", "I am 42"));
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

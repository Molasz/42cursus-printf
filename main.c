/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:30:54 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/16 19:08:00 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char *s, char *v)
{
	int	expected;
	int	ft;

	expected = printf(s, v);
	ft = ft_printf(s, v);
	printf("printf:%d ft_printf:%d\n", expected, ft);
}

int	main(void)
{
	int	num;

	num = 42;
	printf("Hello world!\n");
	ft_printf("Hello world!\n");
	printf("%s\n", "Hello World!");
	ft_printf("%s\n", "Hello World!");
	printf("%i %d %u\n", 0, -42, 42);
	ft_printf("%i %d %u\n", 0, -42, 42);
	printf("%% %c %s\n", '$', "Hello World");
	ft_printf("%% %c %s\n", '$', "Hello World");
	printf("%p %x %X\n", &num, 42, 42);
	ft_printf("%p %x %X\n", &num, 42, 42);
	printf("%5d|%-5d|%05d\n", num, num, num);
	ft_printf("%5d|%-5d|%05d\n", num, num, num);
	printf("%#x|%#X\n", num, num);
	ft_printf("%#x|%#X\n", num, num);
	printf("% i|%+i\n", num, num);
	ft_printf("% i|%+i\n", num, num);
	ft_print("%s", "");
	return (0);
}

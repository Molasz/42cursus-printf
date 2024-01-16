/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:30:54 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/16 00:42:53 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	ft;
	int	expected;
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
	
	ft = ft_printf("%c %c\n", 1, 0);
	expected = printf("%c %c\n", 1, 0);
	
	printf("ft_printf:%d printf:%d\n", ft, expected);
	return (0);
}

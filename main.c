/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:30:54 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/12 19:05:53 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	num;

	num = 42;
	printf("%s\n", "Hello World!");
	ft_printf("%s\n", "Hello World!");
	printf("%i %d %u\n", 0, -42, 42);
	ft_printf("%i %d %u\n", 0, -42, 42);
	printf("%% %c %s\n", '$', "Hello World");
	ft_printf("%% %c %s\n", '$', "Hello World");
	printf("%p %x %X\n", &num, 42, 42);
	ft_printf("%p %x %X\n", &num, 42, 42);
	ft_printf("------------------------\n");
	printf("%5d|%-5d|%05d|%.5d|\n", num, num, num, num);
	ft_printf("%5d|%-5d|%05d|%.5d|\n", num, num, num, num);
	printf("%#x|%#X\n", num, num);
	ft_printf("%#x|%#X\n", num, num);
	printf("% i|%+i\n", num, num);
	ft_printf("% i|%+i\n", num, num);
	return (0);
}

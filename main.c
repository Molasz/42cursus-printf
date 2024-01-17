/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:30:54 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/17 13:46:40 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char *s)
{
	int	expected;
	int	ft;

	expected = printf(s);
	ft = ft_printf(s);
	printf("printf:%d ft_printf:%d\n", expected, ft);
}
void	ft_prints(char *s, char *v)
{
	int	expected;
	int	ft;

	expected = printf(s, v);
	ft = ft_printf(s, v);
	printf("printf:%d ft_printf:%d\n", expected, ft);
}

void	ft_printc(char *s, char c)
{
	int	expected;
	int	ft;

	expected = printf(s, c);
	ft = ft_printf(s, c);
	printf("printf:%d ft_printf:%d\n", expected, ft);
}

void	ft_printi(char *s, int n)
{
	int	expected;
	int	ft;

	expected = printf(s, n);
	ft = ft_printf(s, n);
	printf("printf:%d ft_printf:%d\n", expected, ft);

}

int	main(void)
{
	int	num;

	num = 42;
	ft_print("Hello world!\n");
	ft_print("");

	ft_printc("%c\n", '$');
	ft_printc("%c\n", 0);
	ft_printc("a%ca\n", 'c');

	ft_prints("%s\n", "Hello world");
	ft_prints("STR:%s\n", "hi");
	ft_prints("%s\n", "");

	ft_printi("%i\n", 42);
	ft_printi("%d\n", 42);
	ft_printi("%i\n", 0);
	ft_printi("%u\n", 42);
	ft_printi("%u\n", -42);
	ft_printi("%x\n", 42);
	ft_printi("%X\n", 42);
	ft_printi("%x\n", 0);
	
	/*
	printf("%5d|%-5d|%05d\n", num, num, num);
	ft_printf("%5d|%-5d|%05d\n", num, num, num);
	printf("%#x|%#X\n", num, num);
	ft_printf("%#x|%#X\n", num, num);
	printf("% i|%+i\n", num, num);
	ft_printf("% i|%+i\n", num, num);
	printf("%5.10s|%3.5d\n", "AAA", 42);
	ft_printf("%5.10s|%3.5d\n", "AAA", 42);
	ft_prints("%.10s\n", "Hello world!");
	*/
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:30:54 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/18 15:42:40 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_setcolor(int expected, int ft)
{
	if (expected == ft)
		printf("\033[0;32m");
	else
		printf("\033[0;31m");
}

void	ft_resetcolor () {
	printf("\033[0m");
}

void	ft_output(int expected, int ft, char *s)
{
	ft_setcolor(expected, ft);
	printf("printf:%d ft_printf:%d | %s", expected, ft, s);
	ft_resetcolor();
}

void	ft_print(char *s)
{
	int	expected;
	int	ft;

	expected = printf(s);
	ft = ft_printf(s);
	ft_output(expected, ft, s);
}

void	ft_prints(char *s, char *v)
{
	int	expected;
	int	ft;

	expected = printf(s, v);
	ft = ft_printf(s, v);
	ft_output(expected, ft, s);
}

void	ft_printc(char *s, char c)
{
	int	expected;
	int	ft;

	expected = printf(s, c);
	ft = ft_printf(s, c);
	ft_output(expected, ft, s);
}

void	ft_printi(char *s, int n)
{
	int	expected;
	int	ft;

	expected = printf(s, n);
	ft = ft_printf(s, n);
	ft_output(expected, ft, s);
}

void	ft_printp(char *s, void *p)
{
	int	expected;
	int	ft;

	expected = printf(s, p);
	ft = ft_printf(s, p);
	ft_output(expected, ft, s);
}

int	main(void)
{
	int	num;

	num = 42;
	ft_printi("%d\n", -10);
/*
	ft_printf("   >>>   MANDATORY   <<<\n\n");
	ft_print("Hello world!\n");
 	ft_print("%%\n");
	ft_print("%%c\n");

	ft_printc("%c\n", '$');
	ft_printc("%c\n", 0);
	ft_printc("a%ca\n", 'c');

	ft_prints("%s\n", "Hello world");
	ft_prints("STR:%s\n", "hi");
	ft_prints("%s\n", "");
	ft_prints("%s\n", NULL);

	ft_printi("%i\n", 42);
	ft_printi("%d\n", -42);
	ft_printi("%d\n", 2147483647);
	ft_printi("%d\n", -2147483648);
	ft_printi("%i\n", 0);
	ft_printi("%u\n", 42);
	ft_printi("%u\n", -42);
	ft_printi("%x\n", 42);
	ft_printi("%X\n", -42);
	ft_printi("%x\n", 0);

	ft_printp("%p\n", &num);
	ft_printp("%p\n", "");
	ft_printp("%p\n", NULL);

	ft_printf("\n\n\n   >>>   BONUS   <<<\n\n");

	ft_print("%5%\n");

	ft_printi("%5d\n", 42);
	ft_printi("%-5d\n", 24);
	ft_printi("%05d\n", -42);
	ft_printi("%0+5d\n", 42);
	ft_printi("%0-5d\n", 0);
	ft_printi("%+5d\n", 42);
	ft_printi("%0 5d\n", 42);
	ft_printi("% +5d\n", 42);
	ft_printi("%.5d\n", 42);
	ft_printi("%+7.5d\n", 42);
	ft_printi("%10.5d\n", 42);
	ft_printi("%5.10d\n", 42);

	ft_printi("%#x\n", 42);
	ft_printi("%#X\n", -42);
	ft_printi("%#x\n", 0);
	ft_printi("%+#x\n", 42);
	ft_printi("% #x\n", 42);
	ft_printi("%#5x\n", 42);
	ft_printi("%#.15x\n", 42);
	ft_printi("%#20.5x\n", 42);
	ft_printi("%-#5x\n", 42);

	ft_printc("%5c\n", 'A');
	ft_printc("%3c\n", 0);

	ft_prints("%.s\n", NULL);
	ft_prints("%.0s\n", "hello");
	ft_prints("%5s\n", "goes over");
	ft_prints("%7.5s\n", "bombastic");
*/	
	return (0);
}

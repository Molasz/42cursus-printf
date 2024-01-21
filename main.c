/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:30:54 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/20 16:32:25 by molasz-a         ###   ########.fr       */
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
	printf("\033[0m\n");
}

void	ft_title (char *s) {
	printf("\033[0;33m\n");
	printf("%s", s);
	ft_resetcolor();
}

void	ft_output(int expected, int ft, char *s)
{
	static int	count = 0;

	ft_setcolor(expected, ft);
	printf("(%d) printf:%d ft_printf:%d | %s", ++count, expected, ft, s);
	ft_resetcolor();
}

void	ft_print(char *s)
{
	int		expected;
	int		ft;

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

void	ft_printi(char *s, long long n)
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
	ft_title("   >>>   MANDATORY   <<<\n\n");
	ft_print("Hello world!\n");
 	ft_print("%%|\n");
	ft_print("%%c|\n");

	ft_printc("%c|\n", '$');
	ft_printc("%c|\n", 0);
	ft_printc("a%ca|\n", 'c');

	ft_prints("%s|\n", "Hello world");
	ft_prints("STR:%s|\n", "hi");
	ft_prints("%s|\n", "");
	ft_prints("%s|\n", NULL);


	ft_printi("%i|\n", 42);
	ft_printi("%d|\n", -6);
	ft_printi("%d|\n", 2147483647);
	ft_printi("%d|\n", -2147483648);
	ft_printi("%i|\n", 0);
	ft_printi("%u|\n", 42);
	ft_printi("%u|\n", -42);

	ft_printi("%x|\n", 42);
	ft_printi("%X|\n", -42);
	ft_printi("%x|\n", 0);

	ft_printp("%p|\n", &num);
	ft_printp("%p|\n", "");
	ft_printp("%p|\n", NULL);

	ft_title("\n\n\n   >>>   BONUS   <<<\n\n");

	ft_print("%5%|\n");
	ft_print("%-5%|\n");
	ft_print("%-05%|\n");

	ft_printi("%+d|\n", 42);
	ft_printi("%+d|\n", -2);
	ft_printi("% d|\n", 0);
	ft_printi("%5d|\n", 42);
	ft_printi("%5d|\n", 2147483647);
	ft_printi("%-5d|\n", 24);
	ft_printi("%05d|\n", -42);
	ft_printi("%0+5d|\n", 42);
	ft_printi("%0-5d|\n", 0);
	ft_printi("%+5d|\n", 42);
	ft_printi("%0 5d|\n", 42);
	ft_printi("% +5d|\n", 42);
	ft_printi("%.5d|\n", 42);
	ft_printi("%+7.5d|\n", 42);
	ft_printi("%10.5d|\n", 42);
	ft_printi("%5.10d|\n", 42);

	ft_printi("%#x|\n", 42);
	ft_printi("%#X|\n", -42);
	ft_printi("%#x|\n", 0);
	ft_printi("%+#x|\n", 42);
	ft_printi("% #x|\n", 42);
	ft_printi("%#5x|\n", 42);
	ft_printi("%#.15x|\n", 42);
	ft_printi("%#20.5x|\n", 42);

	ft_printi("%-#5x|\n", 42);

	ft_printp("%20p|\n", &num);
	ft_printp("%25.20p|\n", &num);

	ft_printc("%5c|\n", 'A');
	ft_printc("%3c|\n", 0);
	ft_printc("%015c|\n", 'c');

	ft_prints("%15s|\n", NULL);
	ft_prints("%3s|\n", "hello world");
	ft_prints("%25s|\n", "hello world");
	ft_prints("%-25s|\n", "hello world");
	ft_prints("%5.5s|\n", "hello world");
	ft_prints("%15.5s|\n", "hello world");
	ft_prints("%5.20s|\n", "hello world");
	ft_prints("%5.10s|\n", NULL);
	ft_prints("%5.3s|\n", NULL);
	ft_prints("%5.5s|\n", NULL);

	ft_title("\n\n\n   >>>   EXTRA   <<<\n\n");

	ft_printi("%08.5i|\n", 34);
	/*
	ft_printi("%010.5i|\n", -216);
	ft_printi("%08.5i|\n", 0);
	ft_printi("%08.3i|\n", 8375);
	ft_printi("%08.3i|\n", -8473);
	ft_printi("%.0i|\n", 0);
	ft_printi("%.i|\n", 0);
	ft_printi("%5.0i|\n", 0);
	ft_printi("%5.i|\n", 0);
	ft_printi("%-5.0i|\n", 0);
	ft_printi("%-5.i|\n", 0);
	ft_printi("%08.5d|\n", 34);
	ft_printi("%010.5d|\n", -216);
	ft_printi("%08.5d|\n", 0);
	ft_printi("%08.3d|\n", 8375);
	ft_printi("%08.3d|\n", -8473);
	ft_printi("%.0d|\n", 0);
	ft_printi("%.d|\n", 0);
	ft_printi("%5.0d|\n", 0);
	ft_printi("%5.d|\n", 0);
	ft_printi("%-5.0d|\n", 0);
	ft_printi("%-5.d|\n", 0);

	ft_printi("%20.5u\n|", 1024u);
	*/

	return (0);
}

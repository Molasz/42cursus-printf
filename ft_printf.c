/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:13:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/09 00:21:58 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	args_check(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		ft_putp_fd(va_arg(args, void *), 1);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		ft_puthexl_fd(va_arg(args, unsigned long), 1);
	else if (c == 'X')
		ft_puthexu_fd(va_arg(args, unsigned long), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

int	*flags_check(const char *s, int i, va_list args)
{
	static int flags[5];
	int flag;
	
	//int	justify_width;
	//int	justify_left;
	//int	x_head;
	//int	sign;
	//int	flag;
	flag = 0;
	while (flag < 5)
		flags[flag++] = 0;
	while (flag)
	{
		if (s[i] == '-')
			flags[2] = 1;
		else if (s[i] == '0' || s[i] == '.')
			flags[2] = 2;
		else if (s[i] == '#')
			flags[3] = 1;
		else if (s[i] == ' ')
			flags[4] = -1;
		else if (s[i] == '+')
			flags[4] = 1;
		else if (s[i] >= '0' && s[i] <= '9')
			flags[1] = next_number(s + i,);
		else
			flag = 0;
		i++;
	}
	flags[0] = i;
	return (flags);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i = flags_check(s, i, args);
			args_check(s[i], args);
		}
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	return (0);
}

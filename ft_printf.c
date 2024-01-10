/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:13:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/11 00:48:27 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*cstr(int c)
{
	char	*s;

	s = ft_calloc(sizeof (char), 2);
	if (!s)
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

static char	*identifiers_check(char c, va_list args)
{
	char	*s;

	s = NULL;
	if (c == 'c')
		s = cstr(va_arg(args, int));
	else if (c == 's')
		s = va_arg(args, char *);
	else if (c == 'p')
		s = ft_strp(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(args, int));
	else if (c == 'u')
		s = ft_uitoa(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		s = ft_strhex(va_arg(args, unsigned long), c == 'X');
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return (s);
}

static int	justify_check(char c)
{
	if (c == '-')
		return (1);
	else if (c == '0')
		return (2);
	return (0);
}

static int	sign_check(char c)
{
	if (c == '+')
		return (1);
	else if (c == ' ')
		return (2);
	return (0);
}

static int	precision_check(char c)
{
	if (c == '#')
		return (1);
	return (0);
}

static int	*width_check(char *c)
{
	int	*len;

	if (!len[0])
		len[0] = get_nbr(&s[i]);
	else
		len[1] = get_nbr(&s[i]);
}

static int	check_args(char *s, va_list args)
{
	char	*res;
	int		flags[3];
	int		*len;
	int		i;

	i = 0;
	while (!ft_strrchr("cspduxX%", s[i]))
	{
		if (flags[0] != 1)
			flags[0] = justify_check(s[i]);
		if (flags[1] != 1)
			flags[1] = sign_check(s[i]);
		if (flags[2] != 1)
			flags[2] = precision_check(s[i]);
		if (ft_isdigit(s[i]))
			len = width_check(&s[i]);
		i++;
	}
	if (!s[i])
		res = identifiers_check(s[i], args);
	return (i);
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
			check_args(&((char *)s)[i], args);
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	return (0);
}

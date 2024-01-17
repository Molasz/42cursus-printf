/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:13:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/16 23:25:04 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(int *i, char *s, va_list args)
{
	int	len;

	*i += 1;
	len = ft_check_args((char *)&s[*i], args);
	if (len < 0)
		return (-1);
	while (!ft_strchr("cspdiuxX%", s[*i]))
		*i += 1;
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		tmplen;
	int		len;
	int		i;

	va_start(args, s);
	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			tmplen = ft_percent(&i, (char *)s, args);
			if (tmplen < 0)
				return (0);
			len += tmplen;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}

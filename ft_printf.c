/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:13:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/16 19:05:00 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			i++;
			tmplen = ft_check_args((char *)&s[i], args);
			if (tmplen >= 0)
				len += tmplen;
			else
				return (0);
			while (!ft_strchr("cspdiuxX%", s[i]))
				i++;
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

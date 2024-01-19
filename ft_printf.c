/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:13:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/19 14:48:30 by molasz-a         ###   ########.fr       */
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

void	ft_init(int *i, int *len)
{
	*i = -1;
	*len = 0;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		arglen;
	int		len;
	int		i;

	va_start(args, s);
	ft_init(&i, &len);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			arglen = ft_percent(&i, (char *)s, args);
			if (arglen < 0)
				return (-1);
			len += arglen;
		}
		else
		{
			if (write(1, &s[i], 1) < 0)
				return (-1);
			len++;
		}
	}
	va_end(args);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:37:21 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/18 15:42:57 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_addsign(char c, char *s, int *flags, int num)
{
	char	sign;
	char	*res;

	res = s;
	if (ft_strchr("di", c))
	{
		sign = flags[1];
		if (num < 0)
			sign = '-';
		if (sign)
			res = ft_chrstrjoin(sign, s);
	}
	else if (flags[2])
	{
		if (c == 'x')
			res = ft_strjoin("0x", s);
		else if (c == 'X')
			res = ft_strjoin("0X", s);
	}
	else if (c == 'p' && num)
		res = ft_strjoin("0x", s);
	if (res != s && !ft_strchr("di", c))
		free(s);
	return (res);
}

static char	*ft_justify(char c, char *s, int justify, int minlen)
{
	int		width_space;
	char	v;
	char	*tmp;
	char	*res;

	v = ' ';
	width_space = minlen - ft_strlen(s);
	if (justify == 2 && ft_strchr("pdiuxX", c))
		v = '0';
	tmp = ft_calloc(sizeof(char), width_space + 1);
	if (!tmp)
		return (NULL);
	tmp[width_space] = 0;
	while (width_space--)
		tmp[width_space] = v;
	if (justify != 1)
		res = ft_strjoin(tmp, s);
	else
		res = ft_strjoin(s, tmp);
	free(tmp);
	free(s);
	if (!res)
		return (NULL);
	return (res);
}

static char	*ft_precision(char c, char *s, int precision)
{
	size_t	len;
	char	*res;

	res = s;
	len = ft_strlen(s);
	if (precision == -1)
		precision = 0;
	if (c == 's' && len > (size_t)precision)
	{
		res = ft_substr(s, 0, precision);
		free(s);
	}
	if (ft_strchr("pdiupxX", c) && len < (size_t)precision)
		res = ft_justify(c, s, 2, precision);
	return (res);
}

char	*ft_format(char c, char *s, int *flags, int num)
{
	char	*res;

	res = s;
	if (flags[3])
		res = ft_precision(c, res, flags[5]);
	if (!res)
		return (NULL);
	if (flags[4] != -1 && (size_t)flags[4] > ft_strlen(res))
		res = ft_justify(c, res, flags[0], flags[4]);
	if (!res)
		return (NULL);
	if (ft_strchr("dipxX", c))
		res = ft_addsign(c, res, flags, num);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:37:21 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/17 17:12:54 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_addsign(char c, char *s, int sign)
{
	char	*res;

	res = NULL;
	if (sign && (c == 'd' || c == 'i' || c == 'p'))
	{
		res = ft_chrstrjoin(sign, s);
		if (!res)
			return (NULL);
		return (res);
	}
	return (s);
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
	if (c == 's' && len > (size_t)precision)
	{
		res = ft_substr(s, 0, precision);
		free(s);
	}
	if (ft_strchr("pdiuxX", c) && len < (size_t)precision)
		res = ft_justify(c, s, 2, precision);
	return (res);
}

char	*ft_format(char c, char *s, int *flags, int num)
{
	char	*res;

	res = s;
	if (flags[3] && flags[5])
		res = ft_precision(c, res, flags[5]);
	if (!res)
		return (NULL);
	if (num >= 0)
	{
		res = ft_addsign(c, res, flags[1]);
		if (!res)
			return (NULL);
	}
	if ((size_t)flags[4] > ft_strlen(res))
		res = ft_justify(c, res, flags[0], flags[4]);
	return (res);
}

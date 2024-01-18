/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:37:21 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/18 19:35:07 by molasz-a         ###   ########.fr       */
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

static char	*ft_justifystr(char justify, int len)
{
	char	*res;

	res = ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (NULL);
	while (len--)
		res[len] = justify;
	return (res);
}

static char *ft_justify(char c, char *s, int *flags, int num)
{
	char	*res;
	char	*space;
	char	spacechar;
	int		spacesize;
	int		len;
	int		sign;

	sign = 0;
	space = NULL;
	if (ft_strchr("diuxXp", c) && (num < 0 || flags[1]))
		sign = -1;
	len =  - ft_strlen(s);
	if (ft_strchr("diuxXp", c) && flags[3])
	{
		spacechar = '0';
		spacesize = flags[5];
	}
	else if (flags[0] == 2)
	{
		spacechar = '0';
		spacesize = flags[4];
	}
	else if (flags[0] == 1)
	{
		spacechar = ' ';
		spacesize = flags[5];
	}
	else
		return (NULL);
	space = ft_justifystr(spacechar, spacesize - len - sign);
	if (!space)
		return (NULL);
	if (spacechar == '0' || flags[1] == 1)
		res = ft_strjoin(space, s);
	else
		res = ft_strjoin(s, space);
	return (res);
}

static char	*ft_precision(char c, char *s, int precision)
{
	char	*res;

	res = s;
	if (precision == -1)
		precision = 0;
	if (c == 's' && ft_strlen(s)  > (size_t)precision)
	{
		res = ft_substr(s, 0, precision);
		free(s);
	}
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

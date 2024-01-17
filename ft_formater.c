/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:37:21 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/17 01:03:56 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_chrstrjoin(char c, char *s)
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(s);
	res = ft_calloc(sizeof(char), len + 2);
	if (!res)
		return (NULL);
	res[0] = c;
	res[len - 1] = 0;
	i = 0;
	while (len > i)
	{
		i++;
		res[i] = s[i - 1];
	}
	free(s);
	return (res);
}

char	*ft_addsign(char c, char *s, int sign)
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

static char	*ft_justify_width(char c, char *s, int justify, int minlen)
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

static char	*ft_justify_precision(char c, char *s, int *flags)
{
	int		len;
	char	*res;

	len = (int)ft_strlen(s);
	if (len > flags[5])
	{
		res = ft_substr(s, 0, flags[5]);
		free(s);
		if (!res)
			return (NULL);
		return (res);
	}
	else if (len < flags[4])
	{
		flags[0] = 2;
		return (ft_justify_width(c, s, flags[0], flags[4]));
	}
	return (s);
}

char	*ft_justify(char c, char *s, int *flags)
{
	char	*res;

	res = NULL;
	if (flags[3] && flags[5])
		res = ft_justify_precision(c, s, flags);
	else if (flags[4])
		res = ft_justify_width(c, s, flags[0], flags[4]);
	else
		return (s);
	if (!res)
		return (NULL);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:37:21 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/16 18:35:27 by molasz-a         ###   ########.fr       */
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

static char	*ft_justify_width(char c, char *s, int *flags)
{
	int		width_space;
	char	v;
	char	*tmp;
	char	*res;

	v = ' ';
	width_space = flags[4] - ft_strlen(s);
	if (flags[0] == 2 && ft_strchr("pdiuxX", c))
		v = '0';
	tmp = ft_calloc(sizeof(char), width_space + 1);
	if (!tmp)
		return (NULL);
	tmp[width_space] = 0;
	while (width_space--)
		tmp[width_space] = v;
	if (flags[0] != 1)
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
	char	*res;

	res = NULL;
	(void)c;
	(void)s;
	(void)flags;
	return (res);
}

char	*ft_justify(char c, char *s, int *flags)
{
	char	*res;

	res = NULL;
	if (flags[3] && flags[5])
		res = ft_justify_precision(c, s, flags);
	else if (flags[4])
		res = ft_justify_width(c, s, flags);
	else
		return (s);
	if (!res)
		return (NULL);
	return (res);
}

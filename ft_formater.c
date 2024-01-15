/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:37:21 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/15 01:01:23 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_chrstrjoin(char c, char *s)
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
	while (res[++i])
		res[i] = s[i - 1];
	free(s);
	return (res);
}

char	*ft_addsign(char c, char *s, int sign)
{
	char	*res;

	res = NULL;
	if (sign && (c == 'd' || c == 'i' || c == 'p') && s[0] != '-' && s[0] != '0' )
		return (ft_chrstrjoin(sign, res));
	return (s);
}

char	*ft_justify(char *s, int c, int width)
{
	char	*res;
	char	*tmp;
	char	v;

	res = NULL;
	if (width)
	{
		v = ' ';
		if (c == 2) //TODO only numbers
			v = '0';
		tmp = ft_calloc(sizeof(char), width + 1);
		if (!tmp)
			return (NULL);
		tmp[width] = 0;
		while(width--)
			tmp[width] = v;
		if (!c)
			res = ft_strjoin(tmp, s);
		else if (c == 1)
			res = ft_strjoin(s, tmp);
		free(s);
		return (res);
	}
	return (s);
}

char	*ft_hexprefix(char c, char *s, int prefix)
{
	char	*res;

	if (prefix && s[0] == '0' && s[1] == '\0' && (c == 'x' || c == 'X'))
	{
		if (c == 'x')
			res = ft_strjoin("0x", s);
		else
			res = ft_strjoin("0X", s);
		if (!res)
			return (NULL);
		free(s);
		return (res);
	}
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:37:21 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/15 18:49:01 by molasz-a         ###   ########.fr       */
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
	while (len > i)
	{
		i++;
		res[i] = s[i - 1];
	}
	free(s);
	return (res);
}

char	*ft_chrstr(char c)
{
	char	*s;

	s = ft_calloc(sizeof (char), 2);
	if (!s)
		return (NULL);
	s[0] = c;
	return (s);
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

//TODO justify with '0'
char	*ft_justify(char *s, int justify, int width)
{
	char	*res;
	char	*tmp;
	char	v;
	int		width_space;

	res = NULL;
	if (width)
	{
		v = ' ';
		width_space = width - ft_strlen(s);
		if (justify == 2)
			v = '0';
		tmp = ft_calloc(sizeof(char), width_space + 1);
		if (!tmp)
			return (NULL);
		tmp[width_space] = 0;
		while(width_space--)
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
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:13:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/15 19:37:16 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_reallocres(char *s, char *res, char *arg, int lasti, int i)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	tmp = ft_substr(s, lasti, i - lasti - 1);
	if (!tmp)
		return (NULL);
	tmp2 = ft_strjoin(res, tmp);
	free(res);
	free(tmp);
	if (!tmp2)
		return (NULL);
	str = ft_strjoin(tmp2, arg);
	free(tmp2);
	if (ft_strlen(arg))
		free(arg);
	if (!str)
		return (NULL);
	return (str);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	char	*res;
	char	*tmp;
	int		lasti;
	int		i;

	i = 0;
	lasti = 0;
	res = ft_calloc(sizeof (char), 1);
	if (!res)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i++] == '%')
		{
			tmp = args_check(&((char *)s)[i], args);
			if (!tmp)
				return (0);
			res = ft_reallocres((char *)s, res, tmp, lasti, i);
			if (!res)
				return (0);
			while (!ft_strchr("cspdiuxX%", s[i]))
				i++;
			lasti = ++i;
		}
	}
	res = ft_reallocres((char *)s, res, "", lasti, i + 1);
	if (!res)
		return (-1);
	ft_putstr_fd(res, 1);
	i = ft_strlen(res);
	free(res);
	return (i);
}

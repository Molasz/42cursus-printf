/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:13:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/16 12:52:30 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reallocres(char *s, char *res, char *arg, int i)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	tmp = ft_substr(s, 0, i);
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

int	ft_outres(char *s, char *res, int i)
{
	char	*str;
	int		len;

	str = ft_reallocres(s, res, "", i);
	if (!str)
		return (-1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

char	*ft_init_data(int *i, int *lasti)
{
	char	*res;

	*i = 0;
	*lasti = 0;
	res = ft_calloc(sizeof (char), 1);
	if (!res)
		return (NULL);
	return (res);
}

int	ft_movei(char *s, int i)
{
	while (!ft_strchr("cspdiuxX%", s[i]))
		i++;
	return (++i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	char	*res;
	char	*tmp;
	int		lasti;
	int		i;

	va_start(args, s);
	res = ft_init_data(&i, &lasti);
	if (!res)
		return (0);
	while (s[i])
	{
		if (s[i++] == '%')
		{
			tmp = args_check(&((char *)s)[i], args);
			if (!tmp)
				return (0);
			res = ft_reallocres(&((char *)s)[lasti], res, tmp, i - lasti - 1);
			if (!res)
				return (0);
			i = ft_movei((char *)s, i);
			lasti = i;
		}
	}
	return (ft_outres(&((char *)s)[lasti], res, i - lasti));
}

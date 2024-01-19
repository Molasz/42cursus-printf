/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:13:16 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/18 15:49:31 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_chrstr(char c)
{
	char	*s;

	s = ft_calloc(sizeof (char), 2);
	if (!s)
		return (NULL);
	s[0] = c;
	return (s);
}

char	*ft_chrstrjoin(char c, char *s)
{
	char	*res;
	int		len;

	len = ft_strlen(s);
	res = ft_calloc(sizeof(char), len + 2);
	if (!res)
	{
		free(s);
		return (NULL);
	}
	res[0] = c;
	ft_strlcpy(res + 1, s, len + 1);
	free(s);
	return (res);
}

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char *ft_strjustify(char *arg, int size, char c, int left)
{
	char	*res;
	char	*space;
	int		arg_len;
	int		justify_len;
	int		i;

	arg_len = ft_strlen(s);
	justify_len = size - arg_len;
	space = ft_calloc(sizeof(char), justify_len + 1);
	if (!space)
		return(free(arg));
	i = 0;
	while (i < len)
	{
		space[arg_len + i + 1] = c;
		i++;
	}
	if (left)
		res = ft_strjoin(arg, space);
	else
		res = ft_strjoin(space, arg);
	free(arg);
	free(space);
	retun (res);
}
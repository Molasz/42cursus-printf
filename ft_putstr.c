/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:55:33 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/19 18:39:05 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_justify(char *arg, int *flags)
{
	int	len;

	if (flags[0] == 1)
	{
		len = write(1, arg, ft_strlen(arg));
		if (len < 0)
		{
			free(arg);
			return (-1);
		}
		len = ft_putjustify(flags[3] - ft_strlen(arg), flags[0]);
	}
	else
	{
		len = ft_putjustify(flags[3] - ft_strlen(arg), flags[0]);
		if (len < 0)
		{
			free(arg);
			return (-1);
		}
		len = write(1, arg, ft_strlen(arg));
	}
	if (len < 0)
		return (-1);
	return (flags[3]);
}

int	ft_putstr(char *arg, int *flags)
{
	char	*res;
	int		len;

	res = arg;
	if (flags[4])
	{
		res = ft_substr(res, 0, flags[4]);
		free(arg);
		if (!res)
		{
			free(flags);
			return (-1);
		}
	}
	if (flags[3])
		len = ft_putstr_justify(res, flags);
	else
		len = write(1, res, ft_strlen(arg));
	free(res);
	return (len);
}

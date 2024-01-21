/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:22:45 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/21 01:22:56 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_putstr_prec(char *arg, char *res, t_flags *flags, size_t *len)
{
	if (flags->has_precision && flags->precision < *len)
	{
		if (res != arg)
			free(res);
		res = ft_substr(res, 0, flags->precision);
		if (!res)
			return (1);
		*len = flags->precision;
		if (!arg)
			*len = 0;
	}
	return (0);
}

static int	ft_putstr_justify(char *arg, t_flags *flags, size_t len)
{
	if (flags->justify == '0')
	{
		if (ft_putjustify('0', flags->len - len))
			return (-1);
		if (write(1, arg, len) < 0)
			return (-1);
	}
	if (flags->justify == '-')
	{
		if (write(1, arg, len) < 0)
			return (-1);
		if (ft_putjustify(' ', flags->len - len) < 0)
			return (-1);
	}
	else
	{
		if (ft_putjustify(' ', flags->len - len) < 0)
			return (-1);
		if (write(1, arg, len) < 0)
			return (-1);
	}
	return (flags->len);
}

int	ft_putstr(char *arg, t_flags *flags)
{
	char	*res;
	size_t	len;
	int		write_len;

	res = arg;
	if (!arg)
	{
		res = ft_substr("(null)", 0, 6);
		if (!res)
			return (-1);
	}
	len = ft_strlen(res);
	if (ft_putstr_prec(arg, res, flags, &len))
		return (-1);
	if (flags->len >= len)
		write_len = ft_putstr_justify(res, flags, len);
	else
		write_len = write(1, res, len);
	if (write_len < 0)
		return (-1);
	if (res != arg)
		free(res);
	return (write_len);
}

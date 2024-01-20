/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:01:41 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/19 18:49:28 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunsign_precision(char *arg, int *flags, int len)
{
	int	len;

	if (flags->justify == '0')
	{
		len = ft_putjustify(flags[4] - len, 2);
		if (len < 0)
			return (-1);
		len = write(1, arg, len);
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[3] - flags[4], 0);
	}
	else
	{
		len = ft_putjustify(flags[3] - flags[4], 0);
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[4] - len, 2);
		if (len < 0)
			return (-1);
		len = write(1, arg, len);
	}
	return (len);
}

static int	ft_putunsign_justify(char *arg, int *flags, int len)
{
	int	len;

	if (flags[0] == 1)
	{
		len = ft_putjustify(flags[4] - len, flags[0]);
		if (len < 0)
			return (-1);
		len = write(1, arg, len);
	}
	else
	{
		len = write(1, arg, len);
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[4] - len, flags[0]);
	}
	return (len);
}

int	ft_putunsign(unsigned int arg, t_flags *flags)
{
	char	*num;
	int	
	size_t	len;

	num = ft_uitoa(arg);
	if (!num)
		return (-1);
	len = ft_strlen(arg);
	if (flags->precision >= len)
		write_len = ft_putunsign_precision(num, flags, len);
	else if (flags->len > len)
		write_len = ft_putunsign_justify(num, flags, len);
	else
		write_len = write(1, num, len);
	free(num);
	if (write_len < 0)
		return (-1);
	return (write_len);
}

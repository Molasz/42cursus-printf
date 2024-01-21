/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 02:58:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/21 02:58:31 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_putunsign_justify(char *arg, t_flags *flags, size_t len)
{
	if (flags->justify == '0')
	{
		if (ft_putjustify('0', flags->len - len) < 0)
			return (-1);
		if (write(1, arg, len))
			return (-1);
	}
	else if (flags->justify == '-')
	{
		if (write(1, arg, len))
			return (-1);
		if (ft_putjustify(' ', flags->len - len) < 0)
			return (-1);
	}
	else
	{
		if (ft_putjustify('0', flags->len - len) < 0)
			return (-1);
		if (write(1, arg, len))
			return (-1);
	}
	return (flags->len);
}

int	ft_putunsign(unsigned int arg, t_flags *flags)
{
	char	*num;
	int		write_len;
	size_t	len;

	num = ft_uitoa(arg);
	if (!num)
		return (-1);
	len = ft_strlen(num);
	if (flags->precision > 0)
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

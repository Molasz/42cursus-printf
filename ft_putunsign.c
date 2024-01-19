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

static int	ft_putunsign_precision(char *num, int *flags)
{
	int	len;

	if (flags[0] == 1)
	{
		len = ft_putjustify(flags[4] - ft_strlen(num), 2);
		if (len < 0)
			return (ft_free_all(num));
		len = write(1, num, ft_strlen(num));
		if (len < 0)
			return (ft_free_all(num));
		len = ft_putjustify(flags[3] - flags[4], 0);
	}
	else
	{
		len = ft_putjustify(flags[3] - flags[4], 0);
		if (len < 0)
			return (ft_free_all(num));
		len = ft_putjustify(flags[4] - ft_strlen(num), 2);
		if (len < 0)
			return (ft_free_all(num));
		len = write(1, num, ft_strlen(num));
	}
	return (len);
}

static int	ft_putunsign_justify(char *num, int *flags)
{
	int	len;

	if (flags[0] == 1)
	{
		len = ft_putjustify(flags[4] - ft_strlen(num), flags[0]);
		if (len < 0)
			return (ft_free_all(num));
		len = write(1, num, ft_strlen(num));
	}
	else
	{
		len = write(1, num, ft_strlen(num));
		if (len < 0)
			return (ft_free_all(num));
		len = ft_putjustify(flags[4] - ft_strlen(num), flags[0]);
	}
	return (len);
}

int	ft_putunsign(unsigned int arg, int *flags)
{
	char	*num;
	int		len;

	num = ft_uitoa(arg);
	if (!num)
		return (-1);
	if (flags[4])
		len = ft_putunsign_precision(num, flags);
	else if (flags[3])
		len = ft_putunsign_justify(num, flags);
	else
		len = write(1, num, ft_strlen(num));
	if (len < 0)
		return (ft_free_all(num));
	return (flags[4]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:44:38 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/08 02:30:38 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_fd(unsigned long nb, int fd, char *base)
{
	if (nb >= 16)
	{
		ft_puthex_fd(nb / 16, fd, base);
		ft_puthex_fd(nb % 16, fd, base);
	}
	else
		ft_putchar_fd(base[nb], 1);
}

void	ft_puthexl_fd(unsigned long nb, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	ft_puthex_fd(nb, fd, base);
}

void	ft_puthexu_fd(unsigned long nb, int fd)
{
	char	*base;

	base = "0123456789ABCDEF";
	ft_puthex_fd(nb, fd, base);
}

void	ft_putp_fd(void *p, int fd)
{
	ft_putstr_fd("0x", fd);
	ft_puthexl_fd((unsigned long)p, fd);
}

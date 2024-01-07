/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:54:53 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/08 00:47:42 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "libft/libft.h"

int		ft_printf(const char *s, ...);

void	ft_putunbr_fd(unsigned int n, int fd);
void	ft_puthexl_fd(unsigned long nb, int fd);
void	ft_puthexu_fd(unsigned long nb, int fd);
void	ft_putp_fd(void *p, int fd);

#endif

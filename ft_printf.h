/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:54:53 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/19 18:50:54 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# include <stdio.h>

/*
 * FLAGS
 * Justify		0 '-' '0'
 * Sign			0 '+' ' '
 * Prefix		0 1
 * Len			0 size_t
 * Precision   -1 size_t
 */
typedef struct s_flags
{
	char	justify;
	char	sign;
	int		prefix;
	int		has_precision;
	size_t	len;
	size_t	precision;
}	t_flags;

int				ft_printf(const char *s, ...);

int				ft_check_args(char *s, va_list args);
int				ft_identifiers(char c, va_list args, t_flags *flags);

char			*ft_chrstrjoin(char c, char *s);
char			*ft_chrstr(char c);

int				ft_putstr(char *arg, t_flags *flags);

int				ft_putchr(char arg, t_flags *flags);

int				ft_puthex(unsigned long arg, t_flags *flags, int lower, int p);
int				ft_puthex_precision(char *hex, t_flags *flags,
					int pre, int lower);
int				ft_puthex_justify(char *hex, t_flags *flags,
					int pre, int lower);
char			*ft_strhex(unsigned long n, int lower, t_flags *flags);
int				ft_puthex_pre(int prefix, int lower);

int				ft_putunsign(unsigned int arg, t_flags *flags);
int				ft_putunsign_precision(char *arg, t_flags *flags, size_t len);

int				ft_putint(int arg, t_flags *flags);
int				ft_putint_precision(char *num, t_flags *flags,
					int arg, size_t len);
int				ft_putint_justify(char *num, t_flags *flags,
					int arg, size_t len);
int				ft_putint_pre(int num, int sign);

int				ft_putjustify(char c, int size);
char			*ft_uitoa(unsigned int n);
unsigned int	ft_abs(int n);

#endif

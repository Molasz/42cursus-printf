/* ************************************************************************** */
/*                                                                            */
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

int				ft_printf(const char *s, ...);

char			*ft_uitoa(unsigned int n);
char			*ft_strhex(unsigned long n, int lower);
char			*ft_strp(void *p);

int				ft_check_args(char *s, va_list args);
int				ft_identifiers(char c, va_list args, int *flags);

char			*ft_chrstrjoin(char c, char *s);
char			*ft_chrstr(char c);

int				ft_putstr(char *arg, int *flags);
int				ft_putchr(char arg, int *flags);
int				ft_putp(void *arg, int *flags);
int				ft_puthex(unsigned int arg, int *flags, int lower);
int				ft_putunsign(unsigned int arg, int *flags);
int				ft_putint(int arg, int *flags);

unsigned int	ft_abs(int n);
int				ft_putjustify(int size, int zero);
int				ft_free_all(void *p);

#endif

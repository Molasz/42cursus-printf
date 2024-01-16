/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:54:53 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/16 18:37:59 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# include <stdio.h>

int		ft_printf(const char *s, ...);

char	*ft_uitoa(unsigned int n);
char	*ft_strhex(unsigned long n, int lower, int prefix, int pointer);
char	*ft_strp(void *p);

int		ft_check_args(char *s, va_list args);
int		ft_check_identifiers(char c, va_list args, int *flags);
char	*ft_addsign(char c, char *s, int sign);
char	*ft_justify(char c, char *s, int *flags);

#endif

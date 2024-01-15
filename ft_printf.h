/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:54:53 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/15 13:47:45 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# include <stdio.h>

int		ft_printf(const char *s, ...);

char	*ft_uitoa(unsigned int n);
char	*ft_strhex(unsigned long n, int lower, int prefix);
char	*ft_strp(void *p);

char	*args_check(char *s, va_list args);
void	flags_check(char c, int *flags);
int		width_check(char *c, int *nbr);
char	*ft_identifiers_check(char c, va_list args, int *flags);

char	*ft_chrstrjoin(char c, char *s);
char	*ft_chrstr(char c);
char	*ft_addsign(char c, char *s, int sign);
char	*ft_justify(char *s, int justify, int width);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:54:53 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/12 18:56:42 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *s, ...);

char	*ft_uitoa(unsigned int n);
char	*ft_strhex(unsigned long n, int u);
char	*ft_strp(void *p);

void	flags_check(char c, int *flags);
int		width_check(char *c, int *nbr);
char	*identifiers_check(char c, va_list args);

#endif

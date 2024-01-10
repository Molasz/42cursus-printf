/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:44:38 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/10 23:45:34 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*revstr(char *s)
{
	char	temp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	while (i < len / 2)
	{
		temp = s[len - i - 1];
		s[len - i - 1] = s[i];
		s[i] = temp;
		i++;
	}
	return (s);
}

static int	hexlen(unsigned long nb)
{
	int	i;

	i = 0;
	while (nb > 16)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

static char	*strhex(unsigned long nb, char *base)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_calloc(sizeof (char), hexlen(nb));
	if (!s)
		return (NULL);
	while (nb > 16)
	{
		s[i++] = base[nb % 16];
		nb /= 16;
	}
	s[i++] = base[nb % 16];
	s[i] = '\0';
	return (revstr(s));
}

char	*ft_strhex(unsigned long nb, int u)
{
	if (u)
		return (strhex(nb, "0123456789abcdef"));
	return (strhex(nb, "0123456789ABCDEF"));
}

char	*ft_strp(void *p)
{
	return (ft_strhex((unsigned long)p, 0));
}

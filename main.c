/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:30:54 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/16 15:25:57 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char *s, char *v)
{
	int	expected;
	int	ft;

	expected = printf(s, v);
	ft = ft_printf(s, v);
	printf("printf:%d ft_printf:%d\n", expected, ft);
}

int	main(void)
{
	ft_print("%s\n", "");
	ft_print("%s\n", NULL);
	ft_print(" %s \n", "");
	printf("hola%cadeu", 0);
	return (0);
}

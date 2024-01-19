/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:02:37 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/19 18:26:40 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	printf("%s\n", "hi");
	printf("%5s\n", "hi");
	printf("%05s\n", "hi");
	printf("%-5s\n", "hi");
	printf("%10.5s\n", "hello world");
	printf("%010.5s\n", "hello world");

	printf("%c\n", 'A');
	printf("%5c\n", 'A');
	printf("%05c\n", 'A');
	printf("%-5c\n", 'A');
	printf("%10.5c\n", 'A');

	printf("%u\n", 42);
	printf("%5u\n", 42);
	printf("%+u\n", 42);
	printf("%- 5u\n", 42);
	printf("%10.0u\n", 42);
	printf("%-10.5u\n", 42);
	
	printf("%5x\n", 42);
	printf("%#05x\n", 42);
	printf("%-5x\n", 42);
	printf("%05x\n", 42);
	printf("%-10.5x\n", 42);
	printf("%#10.5x\n", 42);
	return (0);
}

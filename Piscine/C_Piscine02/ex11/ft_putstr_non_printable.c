/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:07:37 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/19 16:47:09 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static char	get_hex(char number);
static void	print(char hex[2], char number);

void	ft_putstr_non_printable(char *str)
{
	char	hex[2];

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			print(hex, *str);
			str++;
		}
		write(1, str, 1);
		str++;
	}
	get_hex(15);
}

static void	print(char hex[2], char decimal)
{
	hex[1] = get_hex(decimal % 16);
	hex[0] = get_hex(decimal / 16);
	write(1, "\\", 1);
	write(1, &hex[0], 1);
	write(1, &hex[1], 1);
}

static char	get_hex(char number)
{
	return ("0123456789abcdef"[(int)number]);
}

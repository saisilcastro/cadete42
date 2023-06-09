/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:17:54 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/23 13:58:15 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi(char *str);
char	has_space(char *str, char mem);
char	has_signal(char *str, char *minus, char mem);
int		ft_exp(int max);

int	ft_atoi(char *str)
{
	char	minus;
	char	mem;
	char	total;

	mem = 0;
	total = 0;
	minus = 1;
	mem = has_space(str, mem);
	mem = has_signal(str, &minus, mem);
	while (*(str + mem) && *(str + mem) >= 48 && *(str + mem) <= 57)
	{
		total = total * 10;
		total = total + (*(str + mem) - 48);
		mem++;
	}
	printf("%i\n", total);
	return (total);
}

char	has_signal(char *str, char *minus, char mem)
{
	while (*(str + mem))
	{
		if (*(str + mem) == '-')
			*minus *= -1;
		if (*(str + mem) != '-' && *(str + mem) != '+')
			break ;
		mem++;
	}
	return (mem);
}

char	has_space(char *str, char mem)
{
	while (*(str + mem))
	{
		if ((*(str + mem) != ' ' && *(str + mem) != '\n'
				&& *(str + mem) != '\t' && *(str + mem) != '\r'
				&& *(str + mem) != '\f'))
			break ;
		mem++;
	}
	return (mem);
}

int	ft_exp(int max)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (i < max)
	{
		if (i > 0)
			n *= 10;
		i++;
	}
	return (n);
}

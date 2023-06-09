/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiho-en <cmiho-en@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:31:46 by cmiho-en          #+#    #+#             */
/*   Updated: 2023/03/23 10:32:21 by cmiho-en         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int				index;
	int				sign;
	unsigned int	number;

	index = 0;
	sign = 1;
	number = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = sign * -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		number = number * 10;
		number = number + (str[index] - '0');
		index++;
	}
	return (number * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// 	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
// 	printf("%d\n", ft_atoi(" 	---+1234\rab567"));
// 	printf("%d\n", ft_atoi(" \n\t\r\v\f---+--2147483648ab567"));
// }
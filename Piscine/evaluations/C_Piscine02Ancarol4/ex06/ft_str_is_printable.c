/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol4 <ancarol4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:55:32 by ancarol4          #+#    #+#             */
/*   Updated: 2023/03/18 16:18:27 by ancarol4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] <= 31 || str[i] == 127)
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	test1[7];
// 	char	*test2;
// 	int		result1;
// 	int		result2;

// 	test1[0] = 'h';
// 	test1[1] = 'e';
// 	test1[2] = 'l';
// 	test1[3] = 127;
// 	test1[4] = 'o';
// 	test1[5] = '!';
// 	test1[6] = '\0';

// 	test2 = "A";
// 	result1 = ft_str_is_printable(test1);
// 	result2 = ft_str_is_printable(test2);
// 	printf("caractere não printável: %i\n", result1);
// 	printf("caractere printável: %i\n", result2);
// 	return (0);
// }

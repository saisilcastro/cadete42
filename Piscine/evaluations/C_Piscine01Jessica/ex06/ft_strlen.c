/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmarqu <jesmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:35:34 by jesmarqu          #+#    #+#             */
/*   Updated: 2023/03/22 22:41:56 by jesmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
	str++;
	count++;
	}
	return (count);
}

// int	main(void)
// {
// 	printf ("%d", ft_strlen("gato"));
// }

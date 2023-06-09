/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsilva <clsilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:21:52 by clsilva           #+#    #+#             */
/*   Updated: 2023/03/20 17:46:08 by clsilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void)

{
	int	numbers;

	numbers = '0';
	while (numbers <= '9')
	{
		write (1, &numbers, 1);
	numbers++;
	}
}

/*int	main(void)

{
	ft_print_numbers();
	return (0);
}*/

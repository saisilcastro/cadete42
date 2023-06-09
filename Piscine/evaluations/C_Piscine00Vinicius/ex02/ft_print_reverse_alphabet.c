/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsilva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:42:29 by clsilva           #+#    #+#             */
/*   Updated: 2023/03/09 16:50:12 by clsilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	z;	

	z = 'z';
	while (z >= 'a')
	{	
		write(1, &z, 1);
		z--;
	}
}

/*int	main(void)

{
	ft_print_reverse_alphabet();
	return (0);
}*/

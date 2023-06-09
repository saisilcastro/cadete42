/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasmirs <jkasmirs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:35:57 by jkasmirs          #+#    #+#             */
/*   Updated: 2023/03/08 12:55:19 by jkasmirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	char	letra;

	letra = 'a';
	while (letra != 'z' + 1)
	{
		write (1, &letra, 1);
		letra++;
	}
	write (1, "\n", 1);
}

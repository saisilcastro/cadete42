/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit-of.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:40:40 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/04 05:19:11 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bit_of.h>

void	bit_on(void *byte, int bit)
{
	*((unsigned *)byte) |= (1 << bit);
}

void	bit_off(void *byte, int bit)
{
	*((unsigned *)byte) &= ~(1 << bit);
}

t_STATUS	bit_is_on(unsigned int byte, int bit)
{
	if (byte & (1 << bit))
		return (On);
	return (Off);
}

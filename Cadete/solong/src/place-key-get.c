/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-key-get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:58:10 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/06 13:52:19 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

t_status	place_key_down(t_place *set, t_keyboard_map map)
{
	return (set->gear->key[map]);
}

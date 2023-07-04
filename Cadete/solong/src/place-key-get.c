/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-key-get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:58:10 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/03 00:02:25 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

t_STATUS place_key_get(t_place *set, t_KEYBOARD_MAP map)
{
	return (set->gear->key[map]);
}

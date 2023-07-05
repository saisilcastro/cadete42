/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-key-get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:58:10 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/05 18:04:53 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

t_STATUS	place_key_down(t_place *set, t_KEYBOARD_MAP map)
{
	return (set->gear->key[map]);
}

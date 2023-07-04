/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-keyboard-plugin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:54:04 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/02 23:55:52 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <machine.h>
#include <linux_keyboard_of.h>
#include <plugin/mlx_plugin.h>
#include <stdio.h>

int	mlx_key_down(int keycode, t_machine *set)
{
	set->key[linux_key_get(keycode)] = On;
	return (0);
}

int	mlx_key_up(int keycode, t_machine *set)
{
	set->key[linux_key_get(keycode)] = Off;
	return (0);
}
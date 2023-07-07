/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-destroy-plugin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 07:36:48 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/04 05:36:44 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <plugin/mlx_plugin.h>
#include <stdio.h>

int	mlx_destroy_plugin(t_machine *set)
{
	if (!set)
		return (0);
	set->event &= ~(1 << MACHINE_RUNNING);
	return (1);
}

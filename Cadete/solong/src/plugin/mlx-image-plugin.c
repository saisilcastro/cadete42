/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-image-plugin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:33:47 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/04 05:37:26 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <plugin/mlx_plugin.h>

t_STATUS	mlx_image_load(t_image *set, void *mlx, B8 *path)
{
	if (!set || !path)
		return (Off);
	set->buffer = mlx_xpm_file_to_image(mlx, path,
			&set->size->x, &set->size->y);
	if (set->buffer)
	{
		mlx_get_data_addr(set->buffer, &set->bpp,
			&set->length, &set->endian);
		return (On);
	}
	return (Off);
}

void	mlx_image_pop(t_image *set, void *mlx)
{
	if (!set)
		return ;
	if (set->buffer)
		mlx_destroy_image(mlx, set->buffer);
	free(set);
}

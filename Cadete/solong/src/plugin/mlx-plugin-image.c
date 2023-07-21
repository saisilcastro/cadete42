/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-plugin-image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:33:47 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/20 19:40:12 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_plugin.h>

t_status	mlx_create_image(t_image *set, void *mlx)
{
	if (!set || !mlx)
		return (Off);
	set->buffer = mlx_new_image(mlx, set->size->x, set->size->y);
	if (set->buffer)
	{
		set->addr = mlx_get_data_addr(set->buffer, &set->bpp,
				&set->length, &set->endian);
		return (On);
	}
	return (Off);
}

t_status	mlx_image_load(t_image *set, void *mlx, char *path)
{
	if (!set || !path)
		return (Off);
	set->buffer = mlx_xpm_file_to_image(mlx, path,
			&set->size->x, &set->size->y);
	if (set->buffer)
	{
		set->addr = mlx_get_data_addr(set->buffer, &set->bpp,
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

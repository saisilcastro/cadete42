/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_plugin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:31:09 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/03 16:43:38 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PLUGIN_H
# define MLX_PLUGIN_H

#include <mlx.h>
#include <machine.h>

enum{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};



typedef struct s_mlx_plugin t_mlx_plugin;
struct s_mlx_plugin{
	void    *mlx;
	void    *window;
};

extern t_mlx_plugin *mlx_plugin_push(void);
extern t_STATUS		mlx_plugin_start(t_machine *set);
extern t_STATUS		mlx_image_load(t_image *set, void *mlx, B8 *path);
extern void			mlx_image_pop(t_image *set, void *mlx);
extern void			mlx_start_event(t_machine *set);
extern void			mlx_plugin_pop(t_machine *set);

#endif // MLX_PLUGIN_H
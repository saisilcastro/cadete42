/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_plugin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:31:09 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/21 20:37:58 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PLUGIN_H
# define MLX_PLUGIN_H

# include <mlx.h>
# include <linux_of.h>
# include <machine.h>

typedef struct s_mlx_plugin	t_mlx_plugin;
struct s_mlx_plugin{
	void	*mlx;
	void	*window;
};

extern t_mlx_plugin	*mlx_plugin_push(void);
extern t_status		mlx_plugin_start(t_machine *set);
extern t_status		mlx_create_image(t_image *set, void *mlx);
extern t_status		mlx_image_load(t_image *set, void *mlx, char *path);
extern void			mlx_putchar(t_mlx_plugin *p, char c, t_vi2d pos, int color);
extern void			mlx_plugin_draw(t_machine *set, void *buffer, t_vi2d pos);
extern void			mlx_image_pop(t_image *set, void *mlx);
extern void			mlx_start_event(t_machine *set);
extern void			mlx_plugin_pop(t_machine *set);

#endif // MLX_PLUGIN_H
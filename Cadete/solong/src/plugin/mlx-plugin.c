/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-plugin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:41:41 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/05 13:42:28 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <plugin/mlx_plugin.h>
#include <mlx.h>

t_mlx_plugin	*mlx_plugin_push(void)
{
	t_mlx_plugin	*plugin;

	plugin = (t_mlx_plugin *)malloc(sizeof(t_mlx_plugin));
	plugin->mlx = NULL;
	plugin->window = NULL;
	return (plugin);
}

t_STATUS	mlx_plugin_start(t_machine *set)
{
	void	*lead;
	B32		w;
	B32		h;

	if (!set)
		return (Off);
	((t_mlx_plugin *)set->plugin)->mlx = mlx_init();
	if (!((t_mlx_plugin *)set->plugin)->mlx)
		return (Off);
	lead = ((t_mlx_plugin *)set->plugin)->mlx;
	w = set->size->x;
	h = set->size->y;
	((t_mlx_plugin *)set->plugin)->window = mlx_new_window(lead,
			w, h, set->title);
	if (!set->plugin)
		return (Off);
	return (On);
}

static int	mlx_expose(t_machine *set)
{
	if (!set)
		return (0);
	return (0);
}

extern int	mlx_key_up(int keycode, t_machine *set);
extern int	mlx_key_down(int keycode, t_machine *set);
extern int	mlx_mouse_update(int button, int x, int y, t_machine *set);
extern int	mlx_mouse_press(int button, int x, int y, t_machine *set);
extern int	mlx_mouse_release(int button, int x, int y, t_machine *set);
extern int	mlx_destroy_plugin(t_machine *set);

void	mlx_start_event(t_machine *set)
{
	t_mlx_plugin	*plugin;

	if (!set)
		return ;
	plugin = set->plugin;
	mlx_hook(plugin->window, ON_KEYUP, KEY_PRESS_MASK, mlx_key_up, set);
	mlx_hook(plugin->window, ON_KEYDOWN, KEY_RELEASE_MASK, mlx_key_down, set);
	mlx_expose_hook(plugin->window, mlx_expose, set);
	mlx_mouse_hook(plugin->window, mlx_mouse_update, set);
	mlx_hook(plugin->window, ON_MOUSEDOWN, MOUSE_PRESS_MASK,
		mlx_mouse_press, set);
	mlx_hook(plugin->window, ON_MOUSEUP, MOUSE_RELEASE_MASK,
		mlx_mouse_release, set);
	mlx_hook(plugin->window, ON_DESTROY, NO_EVENT_MASK,
		mlx_destroy_plugin, set);
}

void	mlx_plugin_pop(t_machine *set)
{
	t_mlx_plugin	*plugin;
	t_chained		*next;

	if (!set || !set->plugin)
		return ;
	plugin = set->plugin;
	while (set->image)
	{
		next = set->image->next;
		mlx_image_pop(set->image->data, plugin->mlx);
		free(set->image);
		set->image = next;
	}
	mlx_destroy_window(plugin->mlx, plugin->window);
	mlx_destroy_display(plugin->mlx);
	free(plugin->mlx);
	free(plugin);
}

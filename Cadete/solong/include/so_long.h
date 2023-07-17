/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:47:19 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/15 08:52:12 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <place.h>
# include <map_of.h>

extern void	object_create(t_place *set, t_map *map);
extern void	so_long_execute(char *path);

#endif // SO_LONG_H
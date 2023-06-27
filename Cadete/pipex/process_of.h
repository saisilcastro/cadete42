/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_of.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:31:17 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/26 22:34:44 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_OF_H
# define PROCESS_OF_H

# include "descriptor_of.h"

typedef struct s_process{
	t_descriptor	*descriptor;
	char			*path;
	char			*app;
	char			**parameter;
	char			**flag;
}t_process;

#endif // PROCESS_OF_H
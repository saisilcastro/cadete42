/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descriptor_of.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:39:22 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/27 22:27:15 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESCRIPTOR_OF_H
# define DESCRIPTOR_OF_H

typedef struct s_descriptor{
	int	current;
	int	max;
	int	input;
	int	output;
	int	aux;
}t_descriptor;

#endif // DESCRIPTOR_OF_H
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:39:19 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/21 22:39:21 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOA_BASE_H
# define ITOA_BASE_H

# include <place_print.h>

extern void	itoa_base(void	*plugin, t_conf *c, int nb, int base);

#endif // ITOA_BASE_H
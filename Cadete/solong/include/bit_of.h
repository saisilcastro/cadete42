/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_of.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:38:29 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/04 05:41:58 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_OF_H
# define BIT_OF_H

# include <system_of.h>

extern void		bit_on(void *byte, int bit);
extern void		bit_off(void *byte, int bit);
extern t_STATUS	bit_is_on(unsigned int byte, int bit);

#endif // BIT_OF_H
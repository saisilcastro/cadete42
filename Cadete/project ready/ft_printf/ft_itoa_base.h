/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:31:02 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/13 13:42:11 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_BASE_H
# define FT_ITOA_BASE_H

extern int	ft_putchar_fd(char c, int fd);
extern int	ft_itoa_base(int nb, unsigned char base, unsigned char upper);
extern int	ft_itoa_base_unsigned(unsigned int nb, unsigned char base,
				unsigned char upper);
extern int	ft_itoa_base_long(unsigned long nb, unsigned char base,
				unsigned char upper);

#endif // FT_ITOA_BASE_H
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenedy- <rkenedy-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 02:05:30 by rkenedy-          #+#    #+#             */
/*   Updated: 2023/06/12 02:05:31 by rkenedy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != 0)
	{	
		while (s[i])
		{	
			write(fd, &s[i], 1);
			i++;
		}
	}
}

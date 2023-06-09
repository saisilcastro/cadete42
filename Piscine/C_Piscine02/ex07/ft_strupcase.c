/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:42:43 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/21 16:19:19 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int		pos;
	char	*update;

	update = str;
	pos = 0;
	while (*str)
	{
		if (*str > 96 && *str < 123)
			*(update + pos) = *str - 32;
		else
			*(update + pos) = *str;
		str++;
		pos++;
	}
	str = update;
	return (str);
}

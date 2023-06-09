/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:43:59 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/15 17:15:23 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;

	fd = open("test1.txt", O_RDONLY);
	i = 0;
	while (i < 20)
	{		
		get_next_line(fd);
		i++;
	}
	return (0);
}

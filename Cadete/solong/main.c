/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:34:47 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/30 15:52:05 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, char **argv)
{
	if (argc < 1 || !argv)
		return (-1);
	so_long_execute(argv[1]);
	return (0);
}

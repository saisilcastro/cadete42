/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:34:47 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/07 19:09:47 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <bit_of.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (!argv || argc < 0)
		return (-1);
	so_long_execute(argv[1]);
	return (0);
}

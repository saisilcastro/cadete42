/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:34:47 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/02 21:52:11 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <bit_of.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc < 1 || !argv)
		return (-1);
	so_long_execute(argv[1]);
	return (0);
}

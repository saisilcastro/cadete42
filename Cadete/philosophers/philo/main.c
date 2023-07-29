/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:23:50 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/29 00:37:50 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <life.h>

int	main(int argc, char **argv)
{
	t_life	platao;

	if (argc > 3 && argv)
	{
		life_set(&platao);
		life_update(&platao);
		life_pop(&platao);
	}
	return (0);
}

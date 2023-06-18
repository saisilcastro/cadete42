/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:19:41 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/17 17:51:37 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_setting	*s;
	t_philo		*p;

	s = NULL;
	if ((ac == 6 && !ft_atol(av[5])))
		return (0);
	if (ac >= 5 && ac <= 6 && !check_args(ac, av))
	{
		s = start_setting(ac, av);
		p = the_lords_supper(s);
		clean_all(s, p);
		return (0);
	}
	printf("extra number of arguments or invalid argument\n");
	return (0);
}

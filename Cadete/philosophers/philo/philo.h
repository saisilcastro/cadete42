/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:36:53 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/28 21:15:20 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>

typedef enum e_hand{
	LEFT_HAND,
	RIGHT_HAND
}t_hand;

typedef struct s_philo	t_philo;
struct s_philo{
	pthread_t	*state;
	unsigned	hand:RIGHT_HAND + 1;
};

extern void	philo_set(t_philo *set);
extern int	philo_hand(t_philo *set, t_hand hand);
extern void	philo_status(t_philo *set);

#endif
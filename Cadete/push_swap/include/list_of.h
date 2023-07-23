/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_of.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:23:05 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/23 01:57:10 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_OF_H
# define LIST_OF_H

typedef struct s_list	t_list;
struct s_list{
	int	*a;
	int	*b;
	int	a_max;
	int	b_max;
};

extern void	list_set(t_list *list);
extern void	list_sort(t_list *list);
extern void	list_pop(t_list *list);

#endif
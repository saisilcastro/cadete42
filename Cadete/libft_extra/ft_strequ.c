/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:10:56 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/25 16:43:05 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strequ(char const *s1, char const *s2)
{
	char	*m1;
	char	*m2;

	m1 = (char *)s1;
	m2 = (char *)s2;
	while (*m1 && *m2)
	{
		if (*m1 != *m2)
			return (0);
		m1++;
		m2++;
	}
	if ((!*m1 && *m2) || (*m1 && !*m2))
		return (0);
	return (1);
}

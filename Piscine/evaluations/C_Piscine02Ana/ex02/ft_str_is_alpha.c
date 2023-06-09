/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatarin <acatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:39:38 by acatarin          #+#    #+#             */
/*   Updated: 2023/03/21 11:41:31 by acatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if ((str[a] < 'A' || str[a] > 'Z') && (str[a] < 'a' || str[a] > 'z'))
		{
			return (0);
		}
		a++;
	}
	return (1);
}

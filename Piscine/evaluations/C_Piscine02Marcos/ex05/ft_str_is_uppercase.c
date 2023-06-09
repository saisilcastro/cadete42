/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavnic2 <mavinic2@student.42sp.org.br >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:37:37 by mavnic2           #+#    #+#             */
/*   Updated: 2023/03/21 12:18:08 by mavnic2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (!(*str >= 65 && *str <= 90))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

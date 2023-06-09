/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:18:40 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/03/18 17:19:01 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 'Z' && str[i] < 'a') || (str[i] < 'A' || str[i] > 'z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

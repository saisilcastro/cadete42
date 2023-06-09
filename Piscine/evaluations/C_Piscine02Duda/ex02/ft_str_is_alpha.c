/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meduard2 <meduard2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:54:07 by meduard2          #+#    #+#             */
/*   Updated: 2023/03/23 05:35:46 by meduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (*(str + i) == '\0')
		return (1);
	while (*(str + i))
	{
		if (!((*(str + i) >= 'A' && *(str + i) <= 'Z')
				|| (*(str + i) >= 'a' && *(str + i) <= 'z')))
		{
			return (0);
		}
			i++;
	}
	return (1);
}

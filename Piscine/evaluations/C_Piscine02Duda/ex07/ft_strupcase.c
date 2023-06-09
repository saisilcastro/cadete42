/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meduard2 <meduard2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 06:21:56 by meduard2          #+#    #+#             */
/*   Updated: 2023/03/23 07:05:24 by meduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if ((*(str + i) >= 'a' && *(str + i) <= 'z'))
		{
			(*(str + i) -= 32);
		}
			i++;
	}
	return (str);
}

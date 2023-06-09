/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meduard2 <meduard2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 06:22:02 by meduard2          #+#    #+#             */
/*   Updated: 2023/03/23 07:07:45 by meduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if ((*(str + i) >= 'A' && *(str + i) <= 'Z'))
		{
			(*(str + i) += 32);
		}
			i++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogonca <leogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:26:29 by leogonca          #+#    #+#             */
/*   Updated: 2023/03/17 14:45:55 by leogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		if (str[i -1] == '-' || str[i -1] == '+' || str[i -1] == ' ')
		{
			if (str[i] >= 97 && str[i] <= 122)
			{
			str[i] = str[i] -32;
			}
			if (str[0] >= 97 && str[0] <= 122)
			{
			str[0] = str[0] -32;
			}
		}	
	i++;
	}
	return (str);
}

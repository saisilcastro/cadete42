/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:18:52 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/08 12:10:06 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*update;
	int		pos;

	update = str;
	pos = 0;
	while (*str)
	{
		if (*str > 64 && *str < 91)
			*(update + pos) = *str + 32;
		else
			*(update + pos) = *str;
		str++;
		pos++;
	}
	str = update;
	return (str);
}

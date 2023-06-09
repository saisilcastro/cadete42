/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:39:20 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/20 16:10:52 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_is_upper(char *str);
char	ft_is_lower(char *str);
char	ft_is_alphanumeric(char *str, int pos);
char	ft_in_range(char *str, int pos, int min, int max);

char	*ft_strcapitalize(char *str)
{
	char	*update;
	int		pos;

	update = str;
	pos = 0;
	while (*str)
	{
		if (pos == 0 && ft_is_lower(str))
			*(update + pos) = *str - 32;
		else if (pos > 0)
		{
			if (ft_is_upper(str))
			{
				if (ft_is_alphanumeric(update, pos - 1))
					*(update + pos) += 32;
			}
			else if (!ft_is_lower(str) && ft_in_range(update, pos + 1, 96, 123))
					*(update + pos + 1) -= 32;
		}
		str++;
		pos++;
	}
	str = update;
	return (str);
}

char	ft_is_upper(char *str)
{
	if (*str > 64 && *str < 91)
		return (1);
	return (0);
}

char	ft_is_lower(char *str)
{
	if (*str > 96 && *str < 123)
		return (1);
	return (0);
}

char	ft_is_alphanumeric(char *str, int pos)
{
	if (ft_in_range(str, pos, 96, 123)
		|| ft_in_range(str, pos, 64, 91)
		|| ft_in_range(str, pos, 47, 58))
		return (1);
	return (0);
}

char	ft_in_range(char *str, int pos, int min, int max)
{
	if (*(str + pos) > min && *(str + pos) < max)
		return (1);
	return (0);
}

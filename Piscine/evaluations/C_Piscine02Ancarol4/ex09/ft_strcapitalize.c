/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol4 <ancarol4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:47:18 by ancarol4          #+#    #+#             */
/*   Updated: 2023/03/17 17:04:29 by ancarol4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	capitalize(char c)
{
	c = c - 32;
	return (c);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	is_first_char;
	int	i;

	is_first_char = 1;
	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (is_first_char)
			{
				str[i] = capitalize(str[i]);
				is_first_char = 0;
			}
		}
		else
		{
			is_first_char = 1;
		}
		i++;
	}
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = "saLut, Comment tu vas ? 42mo - deux; cine + et + un ";
// 	ft_strcapitalize(str);
// 	printf("saída:  %s\n", str);
// 	return (0);
// }
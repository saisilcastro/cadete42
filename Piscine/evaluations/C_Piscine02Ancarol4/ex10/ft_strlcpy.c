/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol4 <ancarol4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:19:00 by ancarol4          #+#    #+#             */
/*   Updated: 2023/03/18 16:17:55 by ancarol4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dst_len;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst_len + 1 < size && src[dst_len] != '\0')
	{
		dest[dst_len] = src[dst_len];
		dst_len++;
	}
	if (dst_len < size)
	{
		dest[dst_len] = '\0';
	}
	return (src_len);
}

// #include <stdio.h>
// #include <bsd/string.h>

// int	main(void)
// {
// 	char	src[] = "Hello";
// 	char	dest[] = "oioioi Oioioi";
// 	unsigned int	len;
// 	unsigned int	strlcp;
// 	unsigned int	result;

// 	len = ft_strlen(dest);
// 	strlcp = strlcpy(dest, src, len);
// 	result = ft_strlcpy(dest, src, len);

// 	printf("len: %d\n", len);
// 	printf("strlcp: %d\n", strlcp);
// 	printf("result: %d\n", result);

// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:36:42 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/16 15:41:14 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

#define LEN 2
#define LEN2 12

t_debug	g_t;

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	pos;

	pos = 0;
	while (*(src + pos))
	{
		*(dest + pos) = *(src + pos);
		pos++;
	}
	return (dest);
}

void	init(void)
{
	g_t.buffer = NULL;
	g_t.src = NULL;
	g_t.len = 0;
}

void	menu(MENU_DEBUG menu)
{
	short	i;

	if (menu == CALLOC)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			g_t.buffer = ft_calloc((__INT_MAX__ - 1), sizeof(char));
			if (!g_t.buffer)
				printf("fucking error\n");
			else
			{
				free(g_t.buffer);
				g_t.buffer = NULL;
				printf("fucking freed\n");
			}
		}
	}
	if (menu == MEMSET)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			ft_memset(g_t.mine, '#', sizeof(g_t.mine));
			printf("mine-memset: %s", g_t.mine);
		}
		else
		{
			memset(g_t.std, '#', sizeof(g_t.std));
			printf("std-memset: %s\n", g_t.std);
		}
	}
	if (menu == BZERO)
	{
		if (!g_t.choice)
		{
			ft_bzero(g_t.mine, sizeof(g_t.mine));
			printf("mine-bzero: %s.\n", g_t.mine);
		}
		else
		{
			bzero(g_t.std, sizeof(g_t.std));
			printf("std-bzero: %s.\n", g_t.std);
		}
	}
	if (menu == MEMCPY)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			g_t.src = (char *)malloc(11 * sizeof(char));
			g_t.src[0] = 'h';
			g_t.src[1] = 'e';
			g_t.src[2] = 'l';
			g_t.src[3] = 'l';
			g_t.src[4] = 'o';
			g_t.src[5] = ' ';
			g_t.src[6] = 'w';
			g_t.src[7] = 'o';
			g_t.src[8] = 'r';
			g_t.src[9] = 'l';
			g_t.src[10] = 'd';
			g_t.src[11] = '\0';
			ft_memcpy(g_t.dest, g_t.src, sizeof(g_t.src));
			printf("mine-memcpy: %s\n", g_t.dest);
		}
		else
		{
			g_t.src = (char *)malloc(11 * sizeof(char));
			g_t.src[0] = 'h';
			g_t.src[1] = 'e';
			g_t.src[2] = 'l';
			g_t.src[3] = 'l';
			g_t.src[4] = 'o';
			g_t.src[5] = ' ';
			g_t.src[6] = 'w';
			g_t.src[7] = 'o';
			g_t.src[8] = 'r';
			g_t.src[9] = 'l';
			g_t.src[10] = 'd';
			g_t.src[11] = '\0';
			memcpy(g_t.dest, g_t.src, 15);
			printf("std-memcpy: %s\n", g_t.dest);
		}
	}
	if (menu == MEMMOVE)
	{
		g_t.choice = 1;
		if (!g_t.choice)
		{
			char hello[] = "hell";

			if (ft_memmove(g_t.dest, hello, sizeof(hello)))
				printf("mine-memmove: %s\n", g_t.dest);
		}
		else
		{
			char hello[] = "hell";

			if (memmove(g_t.dest, hello, sizeof(hello)))
			{
				printf("std-memmove: %s\n", g_t.dest);
			}
		}
	}
	if (menu == MEMCHR)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			ft_strcpy(g_t.dest, "www.site.com");
			g_t.buffer = ft_memchr(g_t.dest, '.', 10);
			printf("%s\n", (char *)g_t.buffer);
		}
		else
		{
			ft_strcpy(g_t.dest, "www.site.com");
			g_t.buffer = memchr(g_t.dest, '.', 10);
			printf("%s\n", (char *)g_t.buffer);
		}
	}
	if (menu == MEMCMP)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			g_t.len = ft_memcmp("HELLO", "hello", 5);
			if (g_t.len < 0)
				printf("mine-memcmp: is lesser\n");
			else if (g_t.len == 0)
				printf("mine-memcmp: is equal\n");
			else
				printf("mine-memcmp: is bigger\n");
		}
		else
		{
			g_t.len = memcmp("HELLO", "hello", 5);
			if (g_t.len < 0)
				printf("std-memcmp: is lesser\n");
			else if (g_t.len == 0)
				printf("std-memcmp: is equal\n");
			else
				printf("std-memcmp: is bigger\n");
		}
	}
	if (menu == STRLEN)
	{
		if (!g_t.choice)
		{
			g_t.len = ft_strlen("hello world");
			printf("mine-strlen: %i\n", g_t.len);
		}
		else
		{
			g_t.len = strlen("hello world");
			printf("std-strlen: %i\n", g_t.len);
		}
	}
	if (menu == STRDUP)
	{
		if (!g_t.choice)
		{
			g_t.buffer = ft_strdup("I am alive");
			printf("mine-strdup: %s\n", (char *)g_t.buffer);
			free(g_t.buffer);
		}
		else
		{
			g_t.buffer = strdup("I am alive");
			printf("std-strdup: %s\n", (char *)g_t.buffer);
			free(g_t.buffer);
		}
	}
	if (menu == STRLCAT)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			g_t.len = ft_strlcat(g_t.dest, g_t.src, 10);
		}
		else
		{
			g_t.len = strlcat(g_t.dest, g_t.src, 10);
		}
	}
	if (menu == STRCHR)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			g_t.buffer = ft_strchr("www.bullshit.com", '.');
			printf("mine-strchr: %s\n", (char *)g_t.buffer);
		}
		else
		{
			g_t.buffer = strchr("www.bullshit.com", '.');
			printf("std-strchr: %s\n", (char *)g_t.buffer);
		}
	}
	if (menu == STRRCHR)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			g_t.buffer = ft_strrchr("www.bullshit.com", '.');
			//printf("mine-strrchr: %s\n", (char *)g_t.buffer);
		}
		else
		{
			g_t.buffer = strrchr("www.bullshit.com", '.');
			printf("std-strrchr: %s\n", (char *)g_t.buffer);
		}
	}
	if (menu == STRNSTR)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			g_t.buffer = ft_strnstr("aaabcabcd", "cd", 8);
			if (g_t.buffer)
				printf("mine-strnstr: %s\n", (char *)g_t.buffer);
		}
		else
		{
			g_t.buffer = strnstr("aaabcabcd", "cd", 8);
			if (g_t.buffer)
				printf("std-strnstr: %s\n", (char *)g_t.buffer);
		}
	}
	if (menu == STRNCMP)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			printf("%i\n", ft_strncmp("hello", "hello", 5));
		}
		else
		{
			printf("%i\n", strncmp("hello", "hello", 5));
		}
	}
	if (menu == ATOI)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			printf("mine-atoi: %i\n", ft_atoi("\n\t  \r\f-125789"));
		}
		else
		{
			printf("std-atoi: %i\n", atoi("\n\t  \r\f-125789"));
		}
	}
	if (menu == ISALPHA)
	{
		if (!g_t.choice)
		{
			i = 0;
			printf("mine-isalpha: ");
			while (i < 256)
			{
				if (ft_isalpha(i))
					printf("%i.", i);
				i++;
			}
		}
		else
		{
			i = 0;
			printf("std-isalpha: ");
			while (i < 256)
			{
				if (isalpha(i))
					printf("%i.", i);
				i++;
			}
		}
	}
	if (menu == ISDIGIT)
	{
		if (!g_t.choice)
		{
			i = 0;
			printf("mine-isdigit: ");
			while (i < 256)
			{
				if (ft_isdigit(i))
					printf("%i.", i);
				i++;
			}
		}
		else
		{
			i = 0;
			printf("std-isdigit: ");
			while (i < 256)
			{
				if (isdigit(i))
					printf("%i.", i);
				i++;
			}
		}
	}
	if (menu == ISALNUM)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			i = 0;
			printf("mine-alnum: ");
			while (i < 256)
			{
				if (ft_isalnum(i))
					printf("%i.", i);
				i++;
			}
		}
		else
		{
			i = 0;
			printf("std-alnum: ");
			while (i < 256)
			{
				if (isalnum(i))
					printf("%i.", i);
				i++;
			}
		}
	}
	if (menu == ISASCII)
	{
		g_t.choice = 1;
		if (!g_t.choice)
		{
			i = 0;
			printf("mine-isascii: ");
			while (i < 256)
			{
				if (ft_isascii(i))
					printf("%i.", i);
				i++;
			}
		}
		else
		{
			i = 0;
			printf("std-isascii: ");
			while (i < 256)
			{
				if (isascii(i))
					printf("%i.", i);
				i++;
			}
		}
	}
	if (menu == ISPRINT)
	{
		g_t.choice = 1;
		if (!g_t.choice)
		{
			i = 0;
			printf("mine-isprint: ");
			while (i < 256)
			{
				if (ft_isprint(i))
					printf("%i.", i);
				i++;
			}
		}
		else
		{
			i = 0;
			printf("std-isprint: ");
			while (i < 256)
			{
				if (isprint(i))
					printf("%c.", i);
				i++;
			}
		}
	}
	if (menu == TOUPPER)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			i = 0;
			printf("mine-toupper: ");
			while (i < 256)
			{
				if ((i > 64 && i < 91) || (i > 96 && i < 123))
					printf("%c.", ft_toupper(i));
				i++;
			}
		}
		else
		{
			i = 0;
			printf("std-toupper: ");
			while (i < 256)
			{
				if ((i > 64 && i < 91) || (i > 96 && i < 123))
					printf("%c.", toupper(i));
				i++;
			}
		}
	}
	if (menu == TOLOWER)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			i = 0;
			printf("mine-tolower: ");
			while (i < 256)
			{
				if ((i > 64 && i < 91) || (i > 96 && i < 123))
					printf("%c.", ft_tolower(i));
				i++;
			}
		}
		else
		{
			i = 0;
			printf("std-tolower: ");
			while (i < 256)
			{
				if ((i > 64 && i < 91) || (i > 96 && i < 123))
					printf("%c.", tolower(i));
				i++;
			}
		}
	}
	if (menu == STR_ITERI)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			ft_striteri(g_t.buffer, NULL);
		}
	}
	if (menu == STR_MAPI)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			ft_strmapi(g_t.buffer, NULL);
		}
	}
	if (menu == STR_JOIN)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			ft_strcpy(g_t.dest, "Hi I am a fool ");
			printf("%s\n", ft_strjoin(g_t.dest, "hello world"));
		}
	}
	if (menu == STR_TRIM)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			g_t.buffer = ft_strtrim("abcdba", "acb");
			if (g_t.buffer)
				printf("%s %i\n", (char *)g_t.buffer, ft_strlen(g_t.buffer));
		}
	}
	if (menu == SPLIT)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			char	**array;
			array = ft_split("**********************************hello*********fellow*students*fucker***********", '*');
			while (*array)
			{
				printf("%s\n", *array);
				array++;
			}
		}
	}
	if (menu == ITOA)
	{
		g_t.choice = 0;
		if (!g_t.choice)
		{
			g_t.buffer = ft_itoa(-(__INT_MAX__ + 1));
			printf("mine-itoa: %s.\n", (char *)g_t.buffer);
			//free(g_t.buffer);
		}
	}
	if (menu == PUTCHAR_FD)
	{
		if (!g_t.choice)
		{
			ft_putchar_fd('f', 1);
			ft_putchar_fd('d', 1);
		}
	}
	if (menu == PUTSTR_FD)
	{
		if (!g_t.choice)
			ft_putstr_fd("this is my putstr_fd\n", 1);
	}
	if (menu == PUTENDL_FD)
	{
		if (!g_t.choice)
			ft_putendl_fd("this is my putend_fd", 1);
	}
	if (menu == PUTNBR_FD)
	{
		if (!g_t.choice)
			ft_putnbr_fd(1542, 1);
	}
}

void	destroy(void)
{
	if (g_t.src)
	{
		free(g_t.src);
		g_t.src = NULL;
	}
	if (g_t.buffer)
	{
		free(g_t.buffer);
		g_t.buffer = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:38:39 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/11 15:51:55 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
#define DEBUG_H

#include <string.h>
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <libft.h>

typedef enum{
	CALLOC,
	MEMSET,
	BZERO,
	MEMCPY,
	MEMMOVE,
	MEMCHR,
	MEMCMP,
	STRLEN,
	STRDUP,
	STRLCAT,
	STRCHR,
	STRRCHR,
	STRNSTR,
	STRNCMP,
	ATOI,
	ISALPHA,
	ISDIGIT,
	ISALNUM,
	ISASCII,
	ISPRINT,
	TOUPPER,
	TOLOWER,
	STR_ITERI,
	STR_MAPI,
	SUB_STR,
	STR_JOIN,
	STR_TRIM,
	SPLIT,
	ITOA,
	PUTCHAR_FD,
	PUTSTR_FD,
	PUTENDL_FD,
	PUTNBR_FD,
}MENU_DEBUG;

typedef struct s_debug t_debug;
struct	s_debug
{
	void	*buffer;
	int		len;
	int		choice;
	char	*src;
	char	dest[100];
	char	mine[100];
	char	std[100];
};

extern	void	init(void);
extern void	menu(MENU_DEBUG menu);
extern void	destroy(void);

#endif // DEBUG_H
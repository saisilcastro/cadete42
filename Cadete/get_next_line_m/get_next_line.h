/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:44:53 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/15 17:20:38 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif // BUFFER_SIZE

typedef struct s_byte	t_byte;
struct s_byte{
	char	symbol;
	t_byte	*next;
};

extern t_byte		*byte_get(char set);
extern void			byte_next_last(t_byte **head, t_byte *new);

typedef struct s_file_of{
	unsigned char	done;
	int				last;
	int				pos;
	int				read;
	int				len;
	int				fd;
	char			buffer[BUFFER_SIZE];
	char			*line;
	t_byte			*string;
}t_file_of;

extern char			*get_next_line(int fd);

extern t_file_of	file_start(int fd);
extern void			file_prepare(t_file_of *set);
extern char			*file_read_line(t_file_of *set);
extern void			file_get_line(t_file_of *set);

#endif // GET_NEXT_LINE

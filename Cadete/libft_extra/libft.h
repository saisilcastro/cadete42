#ifndef LIBFT_H
#define LIBFT_H

extern void		*ft_memccpy(void *dest, void *src, int c, size_t n);
extern char		*ft_strcpy(char *dest, const char *src);
extern char		*ft_strncpy(char *dest, const char *src, size_t n);
extern char		*ft_strcat(char *dest, const char *src);
extern char		*ft_strncat(char *dest, const char *src, size_t n);
extern char		*ft_strstr(const char *big, const char *little);
extern int		ft_strcmp(const char *s1, const char *s2);

#endif // LIBFT_H

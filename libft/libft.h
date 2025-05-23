/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:54:39 by zbakour           #+#    #+#             */
/*   Updated: 2025/01/31 17:22:41 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 42

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *dst, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dest_str, const void *src_str, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
char				*ft_strchr(const char *str, int search_str);
char				*ft_strrchr(const char *str, int c);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_strcmp(const char *str1, const char *str2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nitems, size_t size);
char				*ft_strdup(const char *str);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

size_t				ft_strlen_gn(char *str);
char				*ft_strchr_gn(char *str, int c_chr);
char				*ft_strdup_gn(char *str2);
char				*ft_strjoin_gn(char *str1, char *str2);
char				*get_string(char *str);
char				*handle_remaining(char *buff);
void				read_save(int fd, char **str);
char				*get_next_line(int fd);

int					safe_write(const char *str, int len, int *count);
int					ft_putnbr(int n, int count);
int					ft_printf(const char *s, ...);
int					handle_format(char specifier, va_list args, int *count);
int					handle_char(va_list args);
int					handle_string(va_list args);
int					handle_pointer(va_list args);
int					handle_integer(va_list args);
int					handle_unsigned(va_list args);
int					handle_hex(va_list args, int uppercase);
int					handle_percent(void);
int					ft_putubr(unsigned int n, int count);
int					ft_putnbr(int n, int count);
int					ft_puthex(char *base, unsigned long n, int *count);
int					ft_decimal_to_hex(char *base, unsigned int num);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:30:11 by hbuisser          #+#    #+#             */
/*   Updated: 2021/05/03 20:29:01 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

typedef struct s_var
{
	int			len_a;
	int			len_b;
	int			*stack_a;
	int			*stack_b;
	int			flag_v;
	int			flag_c;
	int			size;
}					t_var;

/*Memory Allocation*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_free(char **array, int size);
char			**ft_freearray(char **array);
int				*ft_vcalloc(size_t count, int value);
void			ft_exit(char *arg, int err);

/*Operators*/
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strcmp(char *s1, char *s2);
char			*ft_addchar(char *str, char c);
void			ft_addstr(char ***arr, char *str);
int				ft_arraylen(char **str);
int				ft_intlen(int n);
int				ft_findchar(char *str, char c);
void			ft_intcpy(int *src, int *dst, int len);
int				*ft_sort_nbr(int *arr, int len);
int				get_next_line(int fd, char **line);
int				args_struct(t_var *v, char **av);

/*verify*/
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_arespace(char *line);
int				ft_iswall(int c);
int				ft_isspace_nl(int c);
int				ft_aredigit(char *str);
int				ft_isnbr(char *s);
int				ft_all_spaces(char *str);
int				ft_getnbr(char const *str);

/*Converter*/
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ps_atoi(char *s);
long long		ps_atoll(char *s);
int				add_elem(t_var *v, char stk, int elem);

/*Not Printf*/
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char *str);
void			ft_putchar(char c);
void			ft_putnbr(int n);

#endif

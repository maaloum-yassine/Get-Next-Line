/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:31:28 by ymaaloum          #+#    #+#             */
/*   Updated: 2022/12/02 23:53:13 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_findnl(char *s);
char	*get_next_line(int fd);
char	*ft_checkline(int fd, char *s_static);
char	*ft_findline(char *s_static);
char	*ft_clean_static(char *s_static);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s_static, char *buf);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif

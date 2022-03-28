/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:04:45 by jbach             #+#    #+#             */
/*   Updated: 2022/03/04 18:58:34 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 5

# include <unistd.h>
# include <stdlib.h>

char	*ft_get_next_line(int fd);

int		ft_strchr(const char *s);
char	*ft_getline(char *str);
void	ft_getbuf(char *buf);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_multiplepoint(char	*s);

#endif

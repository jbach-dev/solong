/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:38:11 by jbach             #+#    #+#             */
/*   Updated: 2022/03/21 21:38:13 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_next_line(int fd)
{
	char		*str;
	int			reading;
	static char	buf[BUFFER_SIZE + 1];

	if ((fd < 0 || fd > 1024) || BUFFER_SIZE < 1)
		return (0);
	str = NULL;
	str = ft_strjoin(str, buf);
	reading = 1;
	while (reading && ft_strchr(buf) == 0)
	{
		reading = read(fd, buf, BUFFER_SIZE);
		if (reading < 0)
		{
			free (str);
			return (NULL);
		}
		buf[reading] = '\0';
		str = ft_strjoin(str, buf);
	}
	str = ft_getline(str);
	ft_getbuf(buf);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:04:38 by jbach             #+#    #+#             */
/*   Updated: 2022/01/07 18:04:38 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_getline(char *str)
{
	int		i;
	char	*newstr;

	i = 0;
	if (!str)
		return (NULL);
	if (!ft_strchr(str))
		return (str);
	newstr = malloc(sizeof(char) * (ft_strchr(str) + 1));
	if (!newstr)
		return (NULL);
	while (i < ft_strchr(str))
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[ft_strchr(str)] = '\0';
	free(str);
	return (newstr);
}

void	ft_getbuf(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strchr(buf);
	if (!j)
	{
		buf[0] = '\0';
		return ;
	}
	while (buf[j])
	{
		buf[i] = buf[j];
		i++;
		j++;
	}
	buf[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1 && s2[0] == '\0')
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	if (!join)
		return (NULL);
	while (s1 && s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = '\0';
	free(s1);
	return (join);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

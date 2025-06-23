/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:23:42 by hyakici           #+#    #+#             */
/*   Updated: 2025/06/23 12:24:24 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_reader(int fd, char *buff)
{
	int		sgnal;
	char	*temp;
	char	*oldbuff;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	sgnal = 1;
	while (sgnal != 0 && !ft_strchr(buff, '\n'))
	{
		sgnal = read(fd, temp, BUFFER_SIZE);
		if (sgnal == -1)
			return (free(temp), free(buff), NULL);
		temp[sgnal] = '\0';
		oldbuff = buff;
		buff = ft_strjoin(buff, temp);
		free(oldbuff);
	}
	free(temp);
	return (buff);
}

static char	*ft_line(char *buff)
{
	char	*theline;
	int		i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	theline = ft_calloc(i + 2, 1);
	if (!theline)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		theline[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		theline[i++] = '\n';
	theline[i] = '\0';
	return (theline);
}

static char	*ft_gonext(char *buff)
{
	int		i;
	char	*next;
	char	*oldbuf;

	i = 0;
	oldbuf = buff;
	buff = ft_strchr(buff, '\n');
	if (!buff)
		return (free(oldbuf), NULL);
	buff++;
	if (!*buff)
		return (free(oldbuf), NULL);
	next = ft_calloc(ft_strlen(buff) + 1, 1);
	if (!next)
		return (free(oldbuf), NULL);
	while (buff[i])
	{
		next[i] = buff[i];
		i++;
	}
	free(oldbuf);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = ft_calloc(1, 1);
	buff = ft_reader(fd, buff);
	if (!buff || !*buff)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	nextline = ft_line(buff);
	buff = ft_gonext(buff);
	return (nextline);
}

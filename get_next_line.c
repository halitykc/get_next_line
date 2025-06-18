/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:23:42 by hyakici           #+#    #+#             */
/*   Updated: 2025/06/18 03:40:17 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reader(int fd, char *buff)
{
	char	*tempo;
	int		sgnal;

	sgnal = 1;
	tempo = calloc(BUFFER_SIZE + 1, 1);
	while (sgnal != 0 && !ft_strchr(buff, '\n'))
	{
		sgnal = read(fd, tempo, BUFFER_SIZE);
		tempo[sgnal] = '\0';
		buff = ft_strjoin(buff, tempo);
	}
	free(tempo);
	return (buff);
}

char	*ft_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	buff[i] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*newline;

	buff = calloc(1, 1);
	buff = ft_reader(fd, buff);
	newline = ft_line(buff);
	return (newline);
}

// static char
// ulimit -n
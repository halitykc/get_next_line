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

static char	*ft_reader(int fd, char *buff)    // burada sıkıntı yok doğru okuyor
{
	int sgnal;
	char *temp;
	char *oldbuff;

	temp = calloc(BUFFER_SIZE + 1, sizeof(char));	
	sgnal = 1;
	while (sgnal != 0 && !ft_strchr(buff, '\n'))
	{
		sgnal = read(fd, temp, BUFFER_SIZE);
		temp[sgnal] = '\0';
		oldbuff = buff;
		buff = ft_strjoin(buff,temp);
		free(oldbuff);
	}
	free(temp);
	return (buff);
}

static char	*ft_line(char *buff)
{
	char *theline;
	int i;
	
	i = 0;
	while (buff[i] != '\n')
		i++;
	theline = calloc(i + 2 , 1);
	i = 0;
	while (buff[i] != '\n')
	{
		theline[i] = buff[i];
		i++;
	}
	theline[i] = '\n';
	return (theline);
}

static char *ft_gonext(char *buff)
{
	int i  = 0;
	char * next;
	char *bj;

	bj = buff;
	buff  = ft_strchr(buff, '\n');
	buff++;
	next  = calloc(ft_strlen(buff) + 1, 1);
	while (buff[i])
	{
		next[i] = buff[i];
		i++;
	}
	return (next);
}

char	*get_next_line(int fd)
{
	static char *buff;
	char *myline;
	buff = calloc(1,1);
	buff = ft_reader(fd,buff);
	myline = ft_line(buff);
	buff = ft_gonext(buff);
	return (myline);
}

// static char
// ulimit -n
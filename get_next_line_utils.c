/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:27:16 by hyakici           #+#    #+#             */
/*   Updated: 2025/06/18 00:53:56 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (0);
}
static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*c;

	if (!dest && !src)
		return (dest);
	p = (unsigned char *)dest;
	c = (unsigned char *)src;
	while (n--)
	{
		*p++ = *c++;
	}
	return (dest);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1len;
	int		s2len;
	char	*p;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	p = malloc(s1len + s2len + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, s1len);
	ft_memcpy(p + s1len, s2, s2len);
	p[s1len + s2len] = '\0';
	return (p);
}

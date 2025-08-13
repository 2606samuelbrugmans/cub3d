/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:22:23 by mucabrin          #+#    #+#             */
/*   Updated: 2025/02/06 16:41:48 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strchrdup(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == 0)
			return (NULL);
		i++;
	}
	i++;
	return (ft_strdup((s + i)));
}

static int	ft_schr(char *str, char c, int tmp)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	if (tmp == 1)
		return (i);
	return (-1);
}

static char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * (ft_schr(stash, '\n', 1) + 1));
	if (!line)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_read(int fd, char *stash)
{
	char	*buff;
	int		df;
	char	*tmp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buff)
		return (free(stash), stash = NULL, NULL);
	while (stash && ft_schr(stash, '\n', 0) < 0)
	{
		df = read(fd, buff, BUFFER_SIZE);
		buff[df] = 0;
		if (df == 0)
			break ;
		tmp = ft_strjoin(stash, buff);
		if (!tmp)
		{
			free(stash);
			stash = NULL;
			break ;
		}
		free(stash);
		stash = tmp;
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*tmp;

	if (BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483647)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	stash = ft_read(fd, stash);
	if (ft_strlen(stash) == 0)
		return (free(stash), stash = NULL, NULL);
	line = ft_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	tmp = ft_strchrdup(stash, '\n');
	free(stash);
	stash = tmp;
	return (line);
}

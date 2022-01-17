/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:56:03 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/17 13:16:30 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*process_line(char **s_buf)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while ((*s_buf)[i] != '\n' && (*s_buf)[i])
		i++;
	if ((*s_buf)[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = ft_substr(*s_buf, 0, i);
	tmp = *s_buf;
	*s_buf = ft_substr(*s_buf, i, (ft_strlen(*s_buf) - i));
	free(tmp);
	return (line);
}

void	read_file(int fd, char **s_buf)
{
	int		red_bean;
	char	buffer[BUFFER_SIZE + 1];
	int		eof;
	char	*tmp;

	eof = 0;
	if (!*s_buf)
		*s_buf = ft_strdup("");
	while (!ft_strchr(*s_buf, '\n') && !eof)
	{
		red_bean = read(fd, buffer, BUFFER_SIZE);
		buffer[red_bean] = '\0';
		if (red_bean != BUFFER_SIZE)
			eof = 1;
		tmp = *s_buf;
		*s_buf = ft_strjoin(*s_buf, buffer);
		free(tmp);
	}
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*s_buf[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 )
		return (NULL);
	read_file(fd, &s_buf[fd]);
	ret = process_line(&s_buf[fd]);
	if (!ret)
	{
		free(ret);
		free(s_buf[fd]);
		s_buf[fd] = NULL;
		ret = NULL;
	}
	return (ret);
}

/*
int	main(int ac, char **av)
{
	int		fd;
	char    *gnl;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		while (1)
		{
			gnl = get_next_line(fd);
			if (gnl == NULL)
			{
				close(fd);
				exit (0);
			}
			printf("%s", gnl);
		}
		close(fd);
	}
	return (0);
}
 */
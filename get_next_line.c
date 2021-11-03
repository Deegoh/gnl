/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:56:03 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/11/03 18:05:58 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int		count_nl(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (*str)
	{
		if(*str == '\n')
			i++;
		str++;
	}
	return (i);
}

int		pos_nl(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
	{
		i++;
		if (str[i] == '\n')
			break ;
	}
	return (i);
}

char	*process_line(char **ret, char **s_buf)
{
	int		i;
	char	*n_buf;

	n_buf = NULL;
	i = 0;
	while ((*s_buf)[i] != '\n' && (*s_buf)[i])
		i++;
	if ((*s_buf)[i] == '\n')
	{
		i++;
		*ret = ft_substr(*s_buf, 0, i);
	}
	else if ((*s_buf)[i] == '\0')
		*ret = ft_strdup(*s_buf);
	n_buf = ft_strdup(&(*s_buf)[i]);
	if (i == 0)
		*ret = NULL;
	return (n_buf);
}

char *get_next_line(int fd)
{
	char		*buf;
	char		*ret;
	static char *s_buf = NULL;
	static int	file = 1;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!s_buf)
		s_buf = ft_strdup("");
	while (file && !ft_strchr(s_buf, '\n'))
	{
		file = read(fd, buf, BUFFER_SIZE);
		buf[file] = '\0';
		s_buf = ft_strjoin(s_buf, buf);
	}
	s_buf = process_line(&ret, &s_buf);
	free(buf);
	buf = NULL;
	return (ret);
}
/*
int	main(int ac, char **av)
{
	int		i;
	int		fd;

	i = INDEX;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		printf("START\n");
		while (i--)
		{
			//get_next_line(fd);
			printf("%s", get_next_line(fd));
		}
		printf("FIN\n");
		close(fd);
	}
	return (0);
}
*/

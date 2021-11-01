/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:56:03 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/11/01 17:57:05 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int		countnl(char	*str)
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

int		posnl(char	*str)
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

char *get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*tmp;
	char		*ret;
	int			file;
	char		*nl;
	int			nlpos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);	
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	tmp = NULL;
	if (!str)
		str = ft_strdup("");
	nl = ft_strchr(str, '\n');
	//printf("nl%s\n", nl);
	while (!nl)
	{
		file = read(fd, buf, BUFFER_SIZE);
		if (file <= 0)
		{
			//printf("file:%d\n", file);
			if (!*buf)
			{
				free(buf);
				buf = NULL;
				free(str);
				str = NULL;
				return (NULL);
			}
			ret = ft_strdup(buf);
			//printf("ret:%s\n", ret);
			free(str);
			str = NULL;
			free(buf);
			buf = NULL;
			if (file < 0)
			{
				free(ret);
				return (NULL);
			}
			return (ret);
		}
		buf[file] = '\0';
		if (!str)
			str = ft_strdup("");
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
		nl = ft_strchr(str, '\n');
	}
	nlpos = 0;
	tmp = str;
	while(tmp[nlpos] != '\n')
		nlpos++;
	//printf("nlpos%d", nlpos);
	str = ft_substr(str, nlpos + 1, ft_strlen(tmp));
	tmp[nlpos + 1] = '\0';
	ret = tmp;
	tmp = NULL;
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
		printf("FD\n");
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

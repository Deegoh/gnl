/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:56:03 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/10/26 18:55:06 by tpinto-m         ###   ########.fr       */
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
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*buf;
	int				ret;
	char			*tmp;
//	int				i = 5;

	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE);
	tmp = NULL;
	if (str)
	{
		free(tmp);
		tmp = ft_substr(str, 1, ft_strlen(str));
		free(str);
	}
	while (!ft_strchr(buf, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		if (!tmp)
			tmp = ft_substr(buf, 0, ret);
		else
			tmp = ft_strjoin(tmp, buf);
	}
	if (ret != BUFFER_SIZE)
	{
		tmp = ft_substr(tmp, 0, ret);
		return (tmp);
	}
	tmp = ft_substr(tmp, 0, posnl(tmp) + 1);
	str = ft_strchr(buf, '\n');

//	printf("%d",ret);
	return (tmp);
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
		while (i--)
		{
			printf("%s", get_next_line(fd));
		}
	}
	return (0);
}
*/

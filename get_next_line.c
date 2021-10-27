/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:56:03 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/10/27 17:53:05 by tpinto-m         ###   ########.fr       */
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
/*
char	*get_next_line(int fd)
{
	static char		*str;
	char			*buf;
	int				ret;
	char			*tmp;

	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	tmp = NULL;
	if (countnl(str))
	{
		printf("%s", str);
//		printf("%d", posnl(str));
//		printf("%s", tmp);
		tmp = ft_substr(str, 1, posnl(str));
		if (countnl(str))
			str = ft_strchr(str, '\n');
//		else
//			str = ft_strchr(tmp, '\0');
//		printf("%s", posnl(str));
//		printf("%s", str);
		//tmp = ft_substr(str, 1, ft_strlen(str));
		return (tmp);
	}
	while (!ft_strchr(buf, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		if (!tmp)
		{
			tmp = ft_substr(buf, 0, ret);
		}
		else
		{
			tmp = ft_strjoin(tmp, buf);
		}
		if (ret != BUFFER_SIZE)
			break ;
	}
	//printf("%d", ret);
	if (ret != BUFFER_SIZE)
	{
		//tmp = ft_substr(tmp, 0, ret);
		//printf("%s$", str);
		//printf("%s$", tmp);

		return (NULL);
	}

	tmp = ft_substr(tmp, 0, posnl(tmp) + 1);
	str = ft_strchr(buf, '\n');
	//tmp[posnl(tmp) + 1] = '\0';
	return (tmp);
}
*/

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	char		*buf;
	int			ret;

	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	tmp = NULL;
	if (str)
	{
		tmp = ft_substr(str, 1, posnl(str));
		str = ft_strchr(str + posnl(str), '\n');
		free(tmp);
		return (tmp);
	}
	if (!tmp)
	{
		while (!ft_strchr(buf, '\n'))
		{
			ret = read(fd, buf, BUFFER_SIZE);
			if (ret == -1)
				return (NULL);
			if (!tmp)
				tmp = ft_substr(buf, 0, ret);
			else
				tmp = ft_strjoin(tmp, buf);
			if (ret != BUFFER_SIZE)
				break ;
		}
		if (!tmp)
		{
			if (countnl(buf))
			{
				tmp = ft_substr(buf, 0, posnl(buf) + 1);
				str = ft_strchr(buf, '\n');
			}
		}
	}
	free(tmp);
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
//			get_next_line(fd);
			printf("%s", get_next_line(fd));
		}
//		printf("FIN");
	}
	return (0);
}
*/

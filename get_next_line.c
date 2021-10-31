/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:56:03 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/10/29 15:49:38 by tpinto-m         ###   ########.fr       */
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
	char		*res;
	int			ret;
	static int	i = 0;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);	
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (!str)
			str = ft_strdup("");
		tmp = ft_strjoin(str, buf);
		str = tmp;
		free(tmp);
		ret = read(fd, buf, BUFFER_SIZE);
		if (!ft_strchr(buf,'\n'))
			return (ft_strdup(buf));
	}
	res = ft_substr(str, 0, posnl(str));
	printf("%s\n", res);
	printf("%d\n", ft_strlen(res));
	printf("%d\n", ft_strlen(str));
	printf("%d\n", posnl(str));
	//tmp = ft_substr(str, ft_strlen(res), ft_strlen(str) - posnl(str));
	printf("%s", tmp);
	str = tmp;
	free(tmp);
	free(buf);
	printf("%d", i);
	i++;
	return (res);
}

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
		close(fd);
	}
	return (0);
}


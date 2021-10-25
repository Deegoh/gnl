/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:56:03 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/10/25 17:59:07 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int		countnline(char	*str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if(*str == '\n')
			i++;
		str++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			buf[BUFFER_SIZE];
	int				ret;
	char			*res = NULL;
	int				count;

	if (fd == -1)
		return (NULL);
//	printf("fd%d\n", fd);
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == -1)
		return (NULL);
//	printf("ret%d\n", ret);
	count = countnline(buf);
//	printf("%d", count);
	if (str)
	{
		count = countnline(str);
		//res = ft_substr(str, 0, strlen(buf) - strlen(strchr(buf, '\n')));
		return (str);
	}
	if (count >= 0)
	{
		//printf("%s", buf);
		//printf("if\n");
		//ft_strjoin(str, strchr(buf, '\n'));
		res = ft_substr(buf, 0, strlen(buf) - strlen(strchr(buf, '\n')));
		//printf("res:%s\n", res);
		str = ft_strdup(strchr(buf, '\n'));
	}
	else
	{
		printf("else");
		res = ft_substr(buf, 0, strlen(strchr(buf, '\n')) - strlen(buf));
	}
	return (res);
}

int	main(int ac, char **av)
{
	int		i;
	int		fd;
//	int		ret;
//	char	buf[BUFFER_SIZE];

	i = 2;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
//		ret = read(fd, buf, BUFFER_SIZE);
//		if (ret == -1)
//			return (0);
		while (i--)
		{
			//printf("size:%d|\n", BUFFER_SIZE);//42
			//printf("fd:%d|\n", fd);//3
			//printf("ret:%d|\n", ret);//14
			//printf("buff:|\n%s\n", buf);//txt
			printf("%s\n", get_next_line(fd));
		}

	}
	return (0);
}

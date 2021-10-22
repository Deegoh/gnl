/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:56:03 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/10/22 17:27:22 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	count = 0;

	count++;
	if (fd == -1)
		return (NULL);
	//while (fd)
	//{
		printf("count:%d", count);
	//}
	return (NULL);
}

int	main(int ac, char **av)
{
	int	i;
	int	fd;
	int	ret[BUFFER_SIZE];

	i = 5;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (NULL);
		ret = read(fd, ret, sizeof(BUFFER_SIZE));
		while (i--)
		{
			get_next_line(ret);
			printf("|fd:%d\n", fd);
			printf("|ret:%d\n", ret);
		}

	}
	return (0);
}

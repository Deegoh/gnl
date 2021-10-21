/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:56:03 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/10/21 18:43:09 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	count = 0;

	count += 1;
	(void)fd;
	printf("%d\n%d\n", BUFFER_SIZE, count);
	return (NULL);
}

int	main(void)
{
	int	i;

	i = 5;
	while (i--)
		get_next_line(1);
}

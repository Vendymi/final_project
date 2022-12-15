/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalchaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:58:43 by dalchaev          #+#    #+#             */
/*   Updated: 2022/12/07 11:43:33 by dalchaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_std_map(void)
{
	int		fd;
	int		m;
	int		size;
	char	buf[10];
	char	*arr;

	fd = open("example_file", O_RDWR);
	size = 0;
	while (1)
	{
		m = read(fd, buf, 10);
		size += m;
		if (m == 0)
			break ;
	}
	arr = (char *)malloc(sizeof(char) * size);
	close (fd);
	fd = open("example_file", O_RDWR);
	m = read(fd, arr, size);
	close (fd);
	return (arr);
}

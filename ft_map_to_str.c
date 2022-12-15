/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalchaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:58:43 by dalchaev          #+#    #+#             */
/*   Updated: 2022/12/07 21:04:41 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct map_val
{
	int		size;
	int		len;
	int		map_len;
	char	obstacle;
	char	blank;
	char	fill;
}	t_cur_map;

char	*ft_map_arr(char *map, struct map_val *mp_s)
{
	int		fd;
	int		m;
	int		size;
	char	buf[10];
	char	*arr;

	fd = open(map, O_RDWR);
	size = 0;
	while (1)
	{
		m = read(fd, buf, 10);
		size += m;
		if (m == 0)
			break ;
	}
	mp_s->map_len = size;
	arr = (char *)malloc(sizeof(char) * size);
	close (fd);
	fd = open(map, O_RDWR);
	m = read(fd, arr, size);
	close (fd);
	return (arr);
}

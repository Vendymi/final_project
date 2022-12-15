/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalchaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:38:23 by dalchaev          #+#    #+#             */
/*   Updated: 2022/12/07 21:04:28 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_linelen(char *str);

typedef struct map_val
{
	int		size;
	int		len;
	int		map_len;
	char	obstacle;
	char	blank;
	char	fill;
}	t_cur_map;

void	ft_read_map(struct map_val *map, char *str)
{
	int	i;
	int	a;

	map->size = 0;
	i = 0;
	a = 0;
	while (str[a] != '\n')
		a++;
	while (str[i] >= '0' && str[i] <= '9' && str [i] != '\0' && i < a -3)
	{
		map->size = map->size * 10 + str[i] - 48;
		i++;
	}
	map->blank = str[i];
	map->obstacle = str[++i];
	map->fill = str[++i];
	map->len = ft_linelen(str);
}

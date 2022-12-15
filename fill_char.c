/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalchaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:34:25 by dalchaev          #+#    #+#             */
/*   Updated: 2022/12/07 21:04:00 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct big
{
	int	start_line;
	int	start_collumn;
	int	number_lines;
	int	size_of_square;
	int	size_of_side;
	int	collumn_size;
}	t_big;

typedef struct cur
{
	int	start_line;
	int	start_collumn;
	int	number_lines;
	int	size_of_square;
	int	collumn_size;
}	t_cur;

typedef struct map_val
{
	int		size;
	int		len;
	int		map_len;
	char	obstacle;
	char	blank;
	char	fill;
}	t_cur_map;

int	ft_sqrt(int nb)
{
	int	div;
	int	i;

	i = 0;
	div = 2;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	while (div <= nb / div)
	{
		if (nb % div == 0 && div * div == nb)
			return (div);
		div++;
	}
	return (0);
}

void	ft_fill_char(char **result, t_cur_map *map, t_big b)
{
	int	i;
	int	j;
	int	a;

	a = 0;
	i = b.start_line;
	while (i < b.start_line + b.size_of_side)
	{
		j = b.start_collumn;
		a = 0;
		while (j < map->len && a < b.size_of_side)
		{
			result[i][j] = map->fill;
			j++;
			a++;
		}
		i++;
	}
}	

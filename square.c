/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:32:24 by vmichali          #+#    #+#             */
/*   Updated: 2022/12/07 21:05:16 by vmichali         ###   ########.fr       */
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

int	check_square(t_cur s, int i, int j, t_cur_map map)
{
	int	line;
	int	collumn;

	line = i - s.start_line + 1;
	if (j == map.len - 1)
		collumn = j - s.start_collumn + 1;
	else
		collumn = j - s.start_collumn;
	if (line > collumn)
	{
		return (collumn * collumn);
	}
	else
	{
		return (line * line);
	}
}

int	ft_square(char **str, t_cur s, t_cur_map map, int i)
{
	int	number;
	int	checknumber;
	int	max_j;
	int	j;

	max_j = map.len;
	i = s.start_line - 1;
	checknumber = 0;
	number = 0;
	while (++i < map.size && i - s.start_line <= max_j - s.start_collumn)
	{	
		j = s.start_collumn - 1;
		while (str[i][++j] != '\0')
		{
			if (str[i][j] == map.obstacle || str[i][j + 1] == '\0')
			{
				if (j < max_j)
					max_j = j;
				number = check_square(s, i, max_j, map);
			}
			if (checknumber < number)
				checknumber = number;
		}
	}
	return (checknumber);
}

void	ft_biggest_square(char **str, t_cur s, t_cur_map map, t_big *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	s.size_of_square = 0;
	while (i < map.size)
	{
		j = 0;
		s.start_line = i;
		while (j < map.size)
		{
			s.start_collumn = j;
			s.size_of_square = ft_square(str, s, map, 0);
			if (s.size_of_square > b->size_of_square)
			{
				b->size_of_square = s.size_of_square;
				b->start_line = s.start_line;
				b->start_collumn = s.start_collumn;
			}
			j++;
		}
		i++;
	}
}

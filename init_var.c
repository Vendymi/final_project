/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:10:23 by vmichali          #+#    #+#             */
/*   Updated: 2022/12/07 21:05:07 by vmichali         ###   ########.fr       */
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

typedef struct main_others
{
	char	*str_map;
	char	**result;
}	t_extra;

typedef struct of_structs
{
	struct map_val	*p_map;
	struct big		*p_big;
	struct cur		*p_cur;
}	t_structs;

void	ft_init(struct cur *s, struct big *b)
{
	s->start_line = 0;
	s->start_collumn = 0;
	b->size_of_square = 0;
}

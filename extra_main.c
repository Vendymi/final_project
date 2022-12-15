/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:46:38 by vmichali          #+#    #+#             */
/*   Updated: 2022/12/07 21:05:00 by vmichali         ###   ########.fr       */
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
	struct main_others	*p_oth;
	struct map_val		*p_map;
	struct big			*p_big;
	struct cur			*p_cur;
}	t_structs;

void	ft_fill_char(char **result, t_cur_map *map, t_big b);
void	ft_read_map(struct map_val *map, char *str);
void	ft_print_table(char **str, t_cur_map map);
char	**ft_split_lines(char *str, int size, t_cur_map map);
int		ft_square(char **str, t_cur s, t_cur_map map);
int		ft_sqrt(int nb);
int		ft_linelen(char *str, t_cur_map map);
int		ft_valid_map(char *str, t_cur_map map);
void	ft_biggest_square(char **str, t_cur s, t_cur_map map, struct big *b);
char	*ft_map_arr(char *map, struct map_val *mp_s);
void	ft_init(struct cur *s, struct big *b);
void	ft_free(char **str, char *str1);

void	ft_free(char **str, char *str1)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
	free (str1);
}	

int	ft_go_square(char **argv, int i)
{
	t_cur		s;
	t_big		b;
	t_cur_map	map;
	t_structs	a;	
	t_extra		e;

	a.p_map = &map;
	a.p_big = &b;
	a.p_cur = &s;
	a.p_oth = &e;
	ft_init(a.p_cur, a.p_big);
	e.str_map = ft_map_arr(argv[i], a.p_map);
	ft_read_map(a.p_map, e.str_map);
	if (ft_valid_map(e.str_map, map) == 0)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	e.result = ft_split_lines(e.str_map, map.size, map);
	ft_biggest_square(e.result, s, map, a.p_big);
	b.size_of_side = ft_sqrt(b.size_of_square);
	ft_fill_char(e.result, a.p_map, b);
	ft_print_table(e.result, map);
	ft_free(e.result, e.str_map);
	return (0);
}

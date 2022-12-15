/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalchaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:37:00 by dalchaev          #+#    #+#             */
/*   Updated: 2022/12/06 19:37:05 by dalchaev         ###   ########.fr       */
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
	struct main_others	p_oth;
	struct map_val		*p_map;
	struct big			*p_big;
	struct cur			*p_cur;
}	t_structs;

void	ft_fill_char(char **result, t_cur_map *map, t_big b);
void	ft_read_map(struct map_val *map, char *str);
void	ft_print_table(char **str);
char	**ft_split_lines(char *str, int size, t_cur_map map);
int		ft_square(char **str, t_cur s, t_cur_map map);
int		ft_sqrt(int nb);
int		ft_linelen(char *str, t_cur_map map);
int		ft_go_square(char **argv, int i);
int		ft_go_square_std(void);
void	ft_biggest_square(char **str, t_cur s, t_cur_map map, struct big *b);
char	*ft_map_arr(char *map);
void	ft_init(struct cur *s, struct big *b);
char	*ft_std_map(void);

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		ft_go_square_std();
	}
	else
	{
		while (i < argc)
		{
			ft_go_square(argv, i);
			i++;
		}
	}
	return (0);
}

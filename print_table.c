/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:04:31 by vmichali          #+#    #+#             */
/*   Updated: 2022/12/07 21:04:51 by vmichali         ###   ########.fr       */
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

void	ft_print_table(char **str, t_cur_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.size)
	{
		j = 0;
		while (j < map.len)
		{
			write(1, &str[i][j++], 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

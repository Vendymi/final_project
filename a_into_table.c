/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_into_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalchaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:34:05 by dalchaev          #+#    #+#             */
/*   Updated: 2022/12/07 21:03:48 by vmichali         ###   ########.fr       */
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

int	ft_linelen(char *str, t_cur_map map);

int	ft_valid_map(char *str, t_cur_map map)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\n')
		i++;
	if (i < 4)
		return (0);
	if (str[i -1] == str[i -2] || str[i -1] == str[i -3]
		|| str[i -2] == str[i -3])
		return (0);
	while (++i < map.map_len)
	{
		if (str[i] != map.blank && str[i] != map.obstacle && str[i] != '\n')
			return (0);
		if ((str[i] < 10 || (str[i] > 10 && str[i] < 32) || str[i] > 127))
			return (0);
	}
	if (ft_linelen(str, map) < 1)
		return (0);
	return (1);
}

int	ft_linelen(char *str, t_cur_map map)
{
	int	i;
	int	len;
	int	len_check;

	i = 0;
	len = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	i++;
	while (str[i + len] != '\n' && str[i + len] != '\0')
		len++;
	i = i + len;
	len_check = len;
	while (++i < map.map_len)
	{
		len = 0;
		while (str[i] != '\n' && str[i] != '\0')
		{	
			len++;
			i++;
		}
		if (len_check != len)
			return (-1);
	}
	return (len);
}

char	**ft_split_lines(char *str, int size, t_cur_map map)
{
	int		i;
	int		j;
	int		line;
	int		linelen;
	char	**result;

	result = malloc(size * sizeof(char *) + 1);
	i = 0;
	line = 0;
	linelen = ft_linelen(str, map);
	while (str[i++] != '\n')
		i++;
	while (str[i] != '\0')
	{
		j = 0;
		result[line] = malloc(linelen * sizeof(char) + 1);
		while (str[i] != '\n' && str[i] != '\0')
			result[line][j++] = str[i++];
		if (str[i++] == '\n' || str[i++] == '\0')
			result[line][j] = '\0';
		line++;
	}
	result[line] = NULL;
	return (result);
}

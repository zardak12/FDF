/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <kosgrey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:19:35 by kosgrey           #+#    #+#             */
/*   Updated: 2020/08/08 17:41:18 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			parse_massiv(char *line, t_fdf **massiv, int y)
{
	char	**value;
	int		x;

	value = ft_strsplit(line, ' ');
	x = 0;
	while (value[x])
	{
		massiv[y][x].z = ft_atoi(value[x]);
		massiv[y][x].x = x;
		massiv[y][x].y = y;
		massiv[y][x].last = 0;
		free(value[x++]);
	}
	free(value);
	free(line);
	massiv[y][--x].last = 1;
	return (x);
}

t_fdf		**mem(char *file_name)
{
	t_fdf	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		error("file does not exist\n");
	if (!(get_next_line(fd, &line) == 1))
		error("Error\n");
	x = ft_wdcounter(line, ' ');
	y = 0;
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		free(line);
	}
	if (!(new = (t_fdf **)malloc(sizeof(t_fdf *) * (++y + 1))))
		return (NULL);
	while (y > 0)
		if (!(new[--y] = (t_fdf *)malloc(sizeof(t_fdf) * (x + 1))))
			return (NULL);
	close(fd);
	return (new);
}

t_fdf		**parser(char *file_name)
{
	t_fdf	**massiv;
	int		y;
	int		fd;
	char	*line;

	massiv = mem(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	while (get_next_line(fd, &line) > 0)
		parse_massiv(line, massiv, y++);
	massiv[y] = NULL;
	close(fd);
	return (massiv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <kosgrey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:20:01 by kosgrey           #+#    #+#             */
/*   Updated: 2020/08/07 23:03:22 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_1(t_fdf first, t_fdf second, t_fdf *value)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_value(&first, &second, value);
	step_x = second.x - first.x;
	step_y = second.y - first.y;
	max = MAX(MOD(step_x), MOD(step_y));
	step_x /= max;
	step_y /= max;
	color = (second.z || first.z) ? 0xfc0345 : 0xBBFAFF;
	color = (second.z != first.z) ? 0xfc031c : color;
	while ((int)(first.x - second.x) || (int)(first.y - second.y))
	{
		mlx_pixel_put(value->mlx_ptr, value->win_ptr, first.x, first.y, color);
		first.x += step_x;
		first.y += step_y;
		if (first.x > value->win_x || first.y > value->win_y\
				|| first.y < 0 || first.x < 0)
			break ;
	}
}

void	draw(t_fdf **massiv)
{
	int		y;
	int		x;

	print_menu(START);
	y = 0;
	while (massiv[y])
	{
		x = 0;
		while (1)
		{
			if (massiv[y + 1])
				draw_1(massiv[y][x], massiv[y + 1][x], &START);
			if (!massiv[y][x].last)
				draw_1(massiv[y][x], massiv[y][x + 1], &START);
			if (massiv[y][x].last)
				break ;
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <kosgrey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:20:32 by kosgrey           #+#    #+#             */
/*   Updated: 2020/08/07 23:10:43 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_key(int key)
{
	return (key == UP || key == DOWN || key == RIGHT || key == LEFT\
	|| key == 49 || key == 87 || key == 23 || key == PLUS\
	|| key == MINUS || key == ESC || key == 69 || key == 78);
}

void	execute_key(int key, t_fdf **massiv)
{
	if (key == UP)
		START.shift_y += 10;
	if (key == DOWN)
		START.shift_y -= 10;
	if (key == RIGHT)
		START.shift_x -= 10;
	if (key == LEFT)
		START.shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		START.threed = (START.threed) ? 0 : 1;
	if (key == PLUS || key == 69)
		START.scale += 3;
	if (key == MINUS || key == 78)
		START.scale -= 3;
	if (key == ESC)
		exit(0);
}

int		deal_key(int key, t_fdf **massiv)
{
	if (check_key(key))
	{
		mlx_clear_window(START.mlx_ptr, START.win_ptr);
		execute_key(key, massiv);
		print_menu(START);
		draw(massiv);
	}
	return (0);
}

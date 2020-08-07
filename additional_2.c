/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <kosgrey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:18:42 by kosgrey           #+#    #+#             */
/*   Updated: 2020/08/07 22:59:22 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_fdf param)
{
	char *menu;

	menu = "up, down, left, right";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 5, RED, menu);
	menu = "zoom - +/-";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 25, RED, menu);
	menu = "space - change 2d/3d";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 40, RED, menu);
}

void	set_default(t_fdf *value)
{
	value->scale = 20;
	value->z_scale = 1;
	value->threed = 1;
	value->angle = 0.523599;
	value->win_x = 2000;
	value->win_y = 1000;
	value->shift_x = value->win_x / 3;
	value->shift_y = value->win_y / 3;
	value->mlx_ptr = mlx_init();
	value->win_ptr =\
	mlx_new_window(value->mlx_ptr, value->win_x, value->win_y, "FDF");
}

void	error(char *msg)
{
	ft_putstr(msg);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <kosgrey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:21:37 by kosgrey           #+#    #+#             */
/*   Updated: 2020/08/07 22:21:48 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_fdf *a, t_fdf *b, t_fdf *new)
{
	a->x *= new->scale;
	a->y *= new->scale;
	b->x *= new->scale;
	b->y *= new->scale;
	a->z *= new->z_scale;
	b->z *= new->z_scale;
}

void	set_value(t_fdf *first, t_fdf *second, t_fdf *value)
{
	zoom(first, second, value);
	if (value->threed)
	{
		isometric(first, value->angle);
		isometric(second, value->angle);
	}
	first->x += value->shift_x;
	first->y += value->shift_y;
	second->x += value->shift_x;
	second->y += value->shift_y;
}

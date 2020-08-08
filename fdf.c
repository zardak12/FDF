/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <kosgrey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:19:04 by kosgrey           #+#    #+#             */
/*   Updated: 2020/08/07 22:19:19 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf		**massiv;

	if (argc != 2)
		error("Error\n");
	massiv = parser(*++argv);
	set_default(&START);
	draw(massiv);
	mlx_key_hook(START.win_ptr, deal_key, massiv);
	mlx_loop(START.mlx_ptr);
}

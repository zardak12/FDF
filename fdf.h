/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <kosgrey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:21:03 by kosgrey           #+#    #+#             */
/*   Updated: 2020/08/07 23:46:39 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WHITE 		0xBBFAFF
# define RED 		0xfc031c
# define START 		massiv[0][0]
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define ESC		53
# define PLUS		24
# define MINUS		27
# define MAX(a,b)	(a > b ? a : b)
# define MOD(a)		((a<0) ?-a : a)

# include "Libft/includes/libft.h"
# include "Libft/includes/get_next_line.h"
# include <math.h>
# include "minilibx_macos/mlx.h"

typedef struct		s_fdf
{
	float		x;
	float		y;
	float		z;
	int			last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			threed;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}					t_fdf;

int					check_key(int key);
void				execute_key(int key, t_fdf **massiv);
int					deal_key(int key, t_fdf **massiv);
void				draw_1(t_fdf first, t_fdf second, t_fdf *value);
void				draw(t_fdf **massiv);
void				set_default(t_fdf *value);
void				error(char *msg);
void				isometric(t_fdf *new, double angle);
void				print_menu(t_fdf param);
int					parse_massiv(char *line, t_fdf **massiv, int y);
t_fdf				**mem(char *file_name);
t_fdf				**parser(char *file_name);
void				zoom(t_fdf *a, t_fdf *b, t_fdf *new);
void				set_value(t_fdf *first, t_fdf *second, t_fdf *value);
int					ft_wdcounter(char const *str, char c);
#endif

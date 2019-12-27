/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <kkhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:33:51 by kkhabour          #+#    #+#             */
/*   Updated: 2019/12/27 20:52:04 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dda(t_pixel start, t_pixel end, void *mlx_ptr, void *mlx_win)
{
	double dx;
	double dy;
	double step;
	double x;
	double y;

	x = start.x;
	y = start.y;
	dx = end.x - start.x;
	dy = end.y - start.y;
	step = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	while (1)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, x, y, start.color);
		if (round(x) == end.x && round(y) == end.y)
			break ;
		x += (dx / step);
		y += (dy / step);
	}
}

void	add_menu(void *mlx_ptr, void *mlx_win)
{
	mlx_string_put(mlx_ptr, mlx_win, 10, 10, 0xFFFFFF, "p : Parallel mode");
	mlx_string_put(mlx_ptr, mlx_win, 10, 30, 0xFFFFFF, "i : Iso mode");
	mlx_string_put(mlx_ptr, mlx_win, 10, 50, 0xFFFFFF, "+ : increment z value");
	mlx_string_put(mlx_ptr, mlx_win, 10, 70, 0xFFFFFF, "- : decrement z value");
	mlx_string_put(mlx_ptr, mlx_win, 10, 90, 0xFFFFFF, "scroll up : zoom in");
	mlx_string_put(mlx_ptr, mlx_win, 10, 110,
			0xFFFFFF, "scroll down : zoom out");
	mlx_string_put(mlx_ptr, mlx_win, 10, 130,
			0xFFFFFF, "Arrow keys: Move shape");
}

void	draw(t_map data)
{
	int y;
	int x;

	mlx_clear_window(data.mlx_ptr, data.mlx_win);
	add_menu(data.mlx_ptr, data.mlx_win);
	y = 0;
	while (y < data.size.y)
	{
		x = 0;
		while (x < data.size.x)
		{
			if (x + 1 != data.size.x)
				dda(data.map[y][x], data.map[y][x + 1],
						data.mlx_ptr, data.mlx_win);
			if (y + 1 != data.size.y)
				dda(data.map[y][x], data.map[y + 1][x],
						data.mlx_ptr, data.mlx_win);
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:22:28 by kkhabour          #+#    #+#             */
/*   Updated: 2019/12/27 12:17:11 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	generate(t_map data, int yy, int xx)
{
	int y;
	int x;
	int temp_y;

	y = -1;
	while (++y < data.size.y)
	{
		x = 0;
		while (x < data.size.x)
		{
			data.map[y][x].x = x * data.zoom;
			data.map[y][x].y = y * data.zoom;
			if (data.mode == ISO)
			{
				temp_y = data.map[y][x].y;
				data.map[y][x].y = (temp_y + data.map[y][x].x) *
					sin(data.rotation) + (data.map[y][x].z * -data.z);
				data.map[y][x].x -= temp_y * cos(data.rotation);
			}
			data.map[y][x].x += xx;
			data.map[y][x].y += yy;
			x++;
		}
	}
	draw(data);
}

int		key_press(int keycode, t_map *data)
{
	if (keycode == 53)
		destroy(data);
	else if (keycode == 34 && data->mode != ISO && (data->mode = ISO))
		generate(*data, data->map[0][0].y, data->map[0][0].x);
	else if (keycode == 35 && data->mode != PARALLEL && (data->mode = PARALLEL))
		generate(*data, data->map[0][0].y, data->map[0][0].x);
	else if (keycode == 126)
		generate(*data, data->map[0][0].y - 5, data->map[0][0].x);
	else if (keycode == 125)
		generate(*data, data->map[0][0].y + 5, data->map[0][0].x);
	else if (keycode == 124)
		generate(*data, data->map[0][0].y, data->map[0][0].x + 5);
	else if (keycode == 123)
		generate(*data, data->map[0][0].y, data->map[0][0].x - 5);
	else if (keycode == 69)
	{
		data->z += 1;
		generate(*data, data->map[0][0].y, data->map[0][0].x);
	}
	else if (keycode == 78)
	{
		data->z -= 1;
		generate(*data, data->map[0][0].y, data->map[0][0].x);
	}
	return (1);
}

int		mouse_press(int button, int x, int y, t_map *data)
{
	if (button == 1)
	{
		data->is_pressed = 1;
		generate(*data, y, x);
	}
	else if (button == 5)
	{
		data->zoom++;
		generate(*data, data->map[0][0].y, data->map[0][0].x);
	}
	else if (button == 4)
	{
		if (data->zoom > 5)
			data->zoom--;
		generate(*data, data->map[0][0].y, data->map[0][0].x);
	}
	return (1);
}

int		mouse_move(int x, int y, t_map *data)
{
	if (data->is_pressed == 1)
		generate(*data, y, x);
	return (1);
}

int		mouse_release(int button, int x, int y, t_map *data)
{
	y = x;
	if (button == 1)
		data->is_pressed = 0;
	return (1);
}

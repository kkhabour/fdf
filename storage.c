/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <kkhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 01:56:43 by kkhabour          #+#    #+#             */
/*   Updated: 2019/12/26 23:38:15 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int			hex_to_decimal(char *str)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res += pow(16, i) * (str[i] - '0');
		else
			res += pow(16, i) * (str[i] - 'A' + 10);
		i++;
	}
	return (res);
}

t_pixel		new_pixel(int z, int color, int y, int x)
{
	t_pixel new;

	new.y = y + 350;
	new.x = x + 350;
	new.z = z;
	if (z != 0 && color == 0)
		new.color = 0xff0800;
	else
		new.color = color;
	return (new);
}

t_pixel		get_z_color(char *tab, int n, int y, int x)
{
	int z;
	int color;

	tab[n] = '\0';
	z = ft_atoi(tab);
	color = hex_to_decimal(tab + (n + 3));
	return (new_pixel(z, color, y, x));
}

t_pixel		filter(char *tab, int y, int x)
{
	t_pixel		pixel;
	int			n;

	if ((n = is_color(tab)) != -1)
		pixel = get_z_color(tab, n, y, x);
	else
		pixel = new_pixel(ft_atoi(tab), 0xFFFFFF, y, x);
	return (pixel);
}

t_pixel		**get_map(int fd, t_mapsize size)
{
	t_pixel		**map;
	char		**tab;
	char		*line;
	int			y;
	int			x;

	y = 0;
	if (!(map = (t_pixel **)malloc(sizeof(t_pixel *) * size.y)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		if (!(map[y] = (t_pixel *)malloc(sizeof(t_pixel) * size.x)))
			return (NULL);
		x = 0;
		while (x < size.x)
		{
			map[y][x] = filter(tab[x], y * ((0.4 * WIDTH) / size.x),
					x * ((0.4 * WIDTH) / size.x));
			x++;
		}
		del_tab(tab, line);
		y++;
	}
	return (map);
}

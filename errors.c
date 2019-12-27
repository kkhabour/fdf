/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 23:14:36 by kkhabour          #+#    #+#             */
/*   Updated: 2019/12/20 23:28:46 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del_tab(char **tab, char *line)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free(line);
}

int		tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	del_map(t_pixel **map, t_mapsize size)
{
	int y;

	y = 0;
	while (y < size.y)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	destroy(t_map *data)
{
	del_map(data->map, data->size);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(EXIT_SUCCESS);
}

void	exit_error(int fd, int status, char *msg)
{
	if (fd == -1)
		close(fd);
	ft_putendl(msg);
	exit(status);
}

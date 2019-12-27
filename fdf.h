/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <kkhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:22:45 by kkhabour          #+#    #+#             */
/*   Updated: 2019/12/27 20:41:53 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define HEIGHT 1000
# define WIDTH 1000
# define ISO 34
# define PARALLEL 35

typedef struct	s_mapsize
{
	int			y;
	int			x;
}				t_mapsize;

typedef struct	s_pixel
{
	int			y;
	int			x;
	int			z;
	int			color;
}				t_pixel;

typedef struct	s_bresenham
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_bresenham;

typedef struct	s_map
{
	t_pixel		**map;
	t_mapsize	size;
	void		*mlx_ptr;
	void		*mlx_win;
	int			mode;
	int			is_pressed;
	int			zoom;
	float		rotation;
	int			z;
}				t_map;

void			exit_error(int fd, int status, char *msg);
void			bresenham(t_pixel start, t_pixel end,
				void *mlx_ptr, void *mlx_win);
int				key_press(int keycode, t_map *param);
int				mouse_press(int button, int x, int y, t_map *param);
int				mouse_move(int x, int y, t_map *param);
int				mouse_release(int button, int x, int y, t_map *param);
void			draw(t_map data);
void			check_map(int fd, t_mapsize *size);
int				is_color(char *line);
int				tab_len(char **tab);
void			del_tab(char **tab, char *line);
void			del_map(t_pixel **map, t_mapsize size);
void			destroy(t_map *data);
t_pixel			**get_map(int fd, t_mapsize size);

#endif

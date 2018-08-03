/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:29:40 by shomami           #+#    #+#             */
/*   Updated: 2018/08/02 15:14:06 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WID 1000
# define LEN 800

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_map
{
	int			len;
	int			wid;
	t_point		**points;
}				t_map;

typedef struct	s_img
{
	void		*ptr;
	char		*data_addr;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef	struct	s_cam
{
	int			x;
	int			y;
}				t_cam;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_cam		*cam;
	int			color;
	int			autorotate;
	int			z;
}				t_fdf;

void			free_all(t_fdf *fdf);
t_point			new_point(int x, int y, int z);
t_img			*init_img(void *mlx);
t_fdf			*init_fdf();
int				handle_keys(int key, t_fdf *fdf);
int				parse(char *filename, t_fdf *fdf);
void			img_pixel_put(t_img *img, int x, int y, int color);
void			draw(t_fdf *fdf);
t_point			project_point(t_fdf *fdf, t_point p);
int				color_select(int color, int num);

#endif

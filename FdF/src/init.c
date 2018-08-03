/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:29:24 by shomami           #+#    #+#             */
/*   Updated: 2018/08/02 15:14:22 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/* frees up everything has been allocated inside fdf pointer*/
void		free_all(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img->ptr);
	free(fdf->img);
	while (fdf->map->len)
		free(fdf->map->points[--fdf->map->len]);
	free(fdf->map->points);
	free(fdf->map);
	free(fdf->cam);
	mlx_del(fdf->mlx);
	free(fdf);
}

/*takes x,y,z as inputs */
t_point		new_point(int x, int y, int z)
{
	t_point		point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

/*creats a t_img struct (an img pointer)*/
t_img		*init_img(void *mlx)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (0);
	if (!(img->ptr = mlx_new_image(mlx, WID, LEN)))
		return (0);
	img->data_addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_size, &img->endian);
	img->bpp /= 8;
	return (img);
}


t_fdf		*init_fdf(void)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (0);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WID, LEN, "FDF");
	fdf->img = init_img(fdf->mlx);
	fdf->map = (t_map*)malloc(sizeof(t_map));
	fdf->cam = (t_cam*)malloc(sizeof(t_cam));
	fdf->cam->x = 0;
	fdf->cam->y = 0;
	fdf->map->len = 0;
	fdf->map->wid = 0;
	fdf->color = 0;
	fdf->autorotate = 0;
	fdf->z = 10;
	return (fdf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:29:27 by shomami           #+#    #+#             */
/*   Updated: 2018/08/02 15:14:18 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>

int		handle_keys(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		free_all(fdf);
		exit(0);
	}
	if (key == 123 || key == 124)
		fdf->cam->x += (key == 123) ? -5 : 5;
	if (key == 125 || key == 126)
		fdf->cam->y += (key == 126) ? -5 : 5;
	if (key == 49)
		fdf->autorotate = (fdf->autorotate == 0) ? 1 : 0;
	if (key == 69)
		fdf->z++;
	if (key == 78 && fdf->z > 0)
		fdf->z--;
	return (0);
}

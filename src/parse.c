/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:29:31 by shomami           #+#    #+#             */
/*   Updated: 2018/08/02 15:29:50 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

char		*next_num(char *line)
{
	while (*line != ' ' && *line)
		line++;
	while (*line == ' ')
		line++;
	return (line);
}

int			get_map_size(t_fdf *fdf, char *filename)
{
	int		fd;
	int		width;
	char	*line;
	char	*tmp;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = line;
		width = fdf->map->wid;
		fdf->map->wid = 0;
		while (*line)
		{
			fdf->map->wid++;
			line = next_num(line);
		}
		if (fdf->map->len > 0 && width != fdf->map->wid)
			return (-1);
		fdf->map->len++;
		free(tmp);
	}
	close(fd);
	return (1);
}

void		malloc_map(t_fdf *fdf)
{
	int		y;

	fdf->map->points = (t_point**)malloc(sizeof(t_point*) * fdf->map->len);
	y = 0;
	while (y < fdf->map->len)
		fdf->map->points[y++] =
			(t_point*)malloc(sizeof(t_point) * fdf->map->wid);
}
/*for each line store x.y and z of each number*/
void		read_row(t_fdf *fdf, int y, char *l)
{
	char	*tmp;
	int		x;

	x = 0;
	tmp = l;
	while (*l)
	{
		fdf->map->points[y][x] = new_point(
			(x + 1) * WID / (fdf->map->wid + 1),
			(y + 1) * LEN / (fdf->map->len + 1),
			ft_atoi(l));
		l = next_num(l);
		x++;
	}
	free(tmp);
}

/*opens the file and reads it 2times,1)gets the size (wid and len) 2)stores x,y,z in each point*/
int			parse(char *filename, t_fdf *fdf)
{
	int		y;
	int		fd;
	char	*l;

	if (get_map_size(fdf, filename) == -1)
		return (-1);
	malloc_map(fdf);
	fd = open(filename, O_RDONLY);
	y = 0;
	while (get_next_line(fd, &l) > 0)
		read_row(fdf, y++, l);
	close(fd);
	return (1);
}

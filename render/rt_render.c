/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:55:32 by absaid            #+#    #+#             */
/*   Updated: 2023/07/15 07:57:52 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"
# define DESTROY	17
# define KEYBOARD	2

static int	destroy_window(t_utils *utils)
{
	// mlx_destroy_image(utils->mlx.mlx, utils->mlx.img);
	mlx_destroy_window(utils->mlx.mlx, utils->mlx.win);
	exit(0);
}

static int	key_hook_handler(int key, t_utils *utils)
{
	(void)utils;
	// printf("%d\n", key);
	if (key == 53)
	{
		mlx_destroy_window(utils->mlx.mlx, utils->mlx.win);
		exit(0);
	}
	return (0);
}

static void	camera_orientation(t_data *data)
{
	data->cam->forvec = normvec(data->cam->forvec);
	data->cam->sidevec = cross_prod((t_vec){0, 1, 0}, data->cam->forvec);
	if(!data->cam->sidevec.x && !data->cam->sidevec.y && !data->cam->sidevec.z)
		data->cam->sidevec = cross_prod((t_vec){1, 0, 0},  data->cam->forvec);
	data->cam->sidevec = normvec(data->cam->sidevec);
	data->cam->upvec = cross_prod(data->cam->sidevec, data->cam->forvec);
	data->cam->upvec = normvec(data->cam->upvec);
	return ;
}

static void	init_new_size(t_mlx	*mlx, t_data *data)
{
	double angle;
	
	camera_orientation(data);
	angle = data->cam->FOV * M_PI / 180;
	mlx->n_width = tan(angle / 2);
	mlx->n_height = HEIGHT * mlx->n_width / WIDTH;
	// printf("NW->%f, NH->%f\n",mlx->n_width, mlx->n_height);
}

void	rt_rendering(t_data *data, t_utils *utils)
{
	int		i;
	int		j;

	j = -1;
	init_new_size(&utils->mlx, data);
	while(++j < HEIGHT)
	{
		i = -1;
		while(++i < WIDTH)
		{
			utils->T.t = -1;
			utils->T.color = data->amlight->color;
			ft_ray(data->cam, i, j, &utils->mlx, &utils->ray);
			find_intersections_with_objects(data, utils);
			int color =  (int)(utils->T.color.x) << 16 |(int)utils->T.color.y << 8 | (int)utils->T.color.z;
			put_pixel_on_image(utils->mlx.img, i, j, color);
		}
	}
	mlx_put_image_to_window(utils->mlx.mlx, utils->mlx.win, \
		utils->mlx.img->img, 0, 0);
	mlx_hook(utils->mlx.win, DESTROY, 0, destroy_window, utils);
	mlx_hook(utils->mlx.win, KEYBOARD, 0, key_hook_handler, utils);
	mlx_loop(utils->mlx.mlx);
}

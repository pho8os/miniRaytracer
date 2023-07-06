/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:55:32 by absaid            #+#    #+#             */
/*   Updated: 2023/07/06 01:33:42 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_render.h"
#include <mlx.h>


// typedef struct {
//     int red;
//     int green;
// } t_color;

// t_color map(int x, int y, int windowWidth, int windowHeight, int startx, int starty) {
//     t_color color;
    
//     color.red = (((x - startx) * 255)) / ((windowWidth) - startx);
//     color.green = ((y - starty) * 255) / ((windowHeight) - starty);
    
//     return color;
// }


void	init_new_size(t_mlx	*mlx, t_data *data)
{
	double angle;
	
	angle = data->cam->FOV * M_PI / 180;
	mlx->n_width = tan(angle / 2);
	mlx->n_height = 400 * mlx->n_width / 450;
	printf("NW->%f, NH->%f\n",mlx->n_width, mlx->n_height);
}
void	rt_rendering(t_data *data)
{
	(void)data;
	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 900, 800, "minirt");
	// TODO : take the FOV and update the new width and the height * 4;
	// TODO : position of camera to send rays;
	init_new_size(&mlx, data);

	mlx_loop(mlx.mlx);
}

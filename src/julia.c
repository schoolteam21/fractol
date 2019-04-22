/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:45:26 by coconroy          #+#    #+#             */
/*   Updated: 2019/03/31 18:46:34 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mouse_juju(int x, int y, t_fractol *fra)
{
	if (fra->mov_juju == 1)
	{
		if (x < fra->width && y < fra->height)
		{
			if (x < fra->width / 2 && y < fra->height / 2)
				fra->c_r += 0.004;
			if (x > fra->width / 2 && y < fra->height / 2)
				fra->c_r -= 0.004;
			if (x < fra->width / 2 && y > fra->height / 2)
				fra->c_i += 0.004;
			if (x > fra->width / 2 && y > fra->height / 2)
				fra->c_i -= 0.004;
		}
		draw_julia(fra);
	}
	return (0);
}

void	init_julia(t_fractol *fra)
{
	fra->width = 1600;
	fra->height = 1000;
	fra->x = 0;
	fra->y = 0;
	fra->i = 0;
	fra->x1 = -4;
	fra->x2 = 2.5;
	fra->y1 = -2.5;
	fra->y2 = 3;
	fra->c_r = -0.63;
	fra->c_i = -0.54;
	fra->itmax = 100;
	fra->zoom = 200;
	fra->mov_juju = 1;
	fra->reshaem = 1;
}

void	exten_julia(t_fractol *fra)
{
	while (fra->z_r * fra->z_r + fra->z_i * fra->z_i < 4 && fra->i < fra->itmax)
	{
		fra->tmp = fra->z_r;
		fra->z_r = fra->z_r * fra->z_r - fra->z_i * fra->z_i + fra->c_r;
		fra->z_i = 2 * fra->z_i * fra->tmp + fra->c_i;
		fra->i++;
	}
}

void	draw_julia(t_fractol *fra)
{
	while (fra->y < fra->height)
	{
		while (fra->x < fra->width)
		{
			fra->z_r = fra->x / fra->zoom + fra->x1;
			fra->z_i = fra->y / fra->zoom + fra->y1;
			exten_julia(fra);
			bfr_pix(fra);
			fra->i = 0;
			fra->x++;
		}
		fra->y++;
		fra->x = 0;
	}
	fra->x = 0;
	fra->y = 0;
	mlx_put_image_to_window(fra->mlx, fra->win, fra->imgptr, 0, 0);
}

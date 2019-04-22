/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spiner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:45:59 by coconroy          #+#    #+#             */
/*   Updated: 2019/03/31 18:51:19 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_spiner(t_fractol *fra)
{
	fra->width = 1600;
	fra->height = 1000;
	fra->x = 0;
	fra->y = 0;
	fra->i = 0;
	fra->x1 = -4;
	fra->x2 = 4;
	fra->y1 = -2.5;
	fra->y2 = 2.5;
	fra->c_r = 0.65;
	fra->c_i = 0.65;
	fra->itmax = 200;
	fra->zoom = 200;
	fra->mov_juju = 0;
	fra->reshaem = 4;
}

void	exten_spiner(t_fractol *fra)
{
	while (fra->z_r * fra->z_r + fra->z_i * fra->z_i < 4 && fra->i < fra->itmax)
	{
		fra->tmp = fra->z_r;
		fra->z_r = fra->z_r * fra->z_r - fra->z_i * fra->z_i + fra->c_r;
		fra->z_i = fra->z_i * fra->tmp + fra->c_i;
		fra->i++;
	}
}

void	draw_spiner(t_fractol *fra)
{
	while (fra->y < fra->height)
	{
		while (fra->x < fra->width)
		{
			fra->c_r = fra->c_r;
			fra->c_i = fra->c_i;
			fra->z_r = fra->x / fra->zoom + fra->x1;
			fra->z_i = fra->y / fra->zoom + fra->y1;
			exten_spiner(fra);
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

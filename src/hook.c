/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:45:05 by coconroy          #+#    #+#             */
/*   Updated: 2019/03/31 18:25:38 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	dlya_strelok(t_fractol *fra)
{
	fra->q = 0.01;
	if (fra->zoom > 1000)
		fra->q = 0.001;
	if (fra->zoom > 5000)
		fra->q = 0.0001;
	if (fra->zoom > 10000)
		fra->q = 0.00001;
	if (fra->zoom > 20000)
		fra->q = 0.000001;
}

void	zoom(t_fractol *fra, int x, int y)
{
	double x_n;
	double y_n;

	if (y > 0 && x > 0)
	{
		x_n = (x / fra->zoom) + fra->x1;
		y_n = (y / fra->zoom) + fra->y1;
		fra->zoom *= 1.35;
		fra->x1 = x_n - (x / fra->zoom);
		fra->y1 = y_n - (y / fra->zoom);
		rehaem(fra);
	}
}

void	dezoom(t_fractol *fra, int x, int y)
{
	double x_n;
	double y_n;

	x_n = (x / fra->zoom) + fra->x1;
	y_n = (y / fra->zoom) + fra->y1;
	fra->zoom /= 1.35;
	fra->x1 = x_n - (x / fra->zoom);
	fra->y1 = y_n - (y / fra->zoom);
	rehaem(fra);
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *fra)
{
	if (mousecode == 4 || mousecode == 1)
		zoom(fra, x, y);
	else if (mousecode == 5 || mousecode == 2)
		dezoom(fra, x, y);
	return (0);
}

int		hook_keydown(int key, t_fractol *fra)
{
	dlya_strelok(fra);
	key == 53 ? ft_exit() : 1;
	key == 18 ? init_julia(fra) : 1;
	key == 19 ? init_mandel(fra) : 1;
	key == 20 ? init_random(fra) : 1;
	key == 21 ? init_spiner(fra) : 1;
	key == 8 ? (fra->color1 = fra->color1 - 10000) : 1;
	key == 9 ? (fra->color1 = fra->color1 + 10000) : 1;
	if (key == 1)
	{
		if (fra->mov_juju == 1)
			fra->mov_juju = 0;
		else
			fra->mov_juju = 1;
	}
	if (key == 123)
		fra->x1 += fra->q;
	if (key == 124)
		fra->x1 -= fra->q;
	if (key == 125)
		fra->y1 -= fra->q;
	if (key == 126)
		fra->y1 += fra->q;
	rehaem(fra);
	return (0);
}

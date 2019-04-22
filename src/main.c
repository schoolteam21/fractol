/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:53:07 by coconroy          #+#    #+#             */
/*   Updated: 2019/03/31 18:36:22 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char*)s1 - *(unsigned char*)s2);
}

void	rehaem(t_fractol *fra)
{
	if (fra->reshaem == 1)
	{
		draw_julia(fra);
		mlx_hook(fra->win, 6, 1L << 6, mouse_juju, fra);
	}
	if (fra->reshaem == 2)
		draw_mandel(fra);
	if (fra->reshaem == 3)
		draw_random(fra);
	if (fra->reshaem == 4)
		draw_spiner(fra);
}

void	mlx_init_it(t_fractol *fra)
{
	fra->mlx = mlx_init();
	fra->win = mlx_new_window(fra->mlx, 1600, 1000, "Fractol");
	fra->imgptr = mlx_new_image(fra->mlx, 1600, 1000);
	fra->imgstr = mlx_get_data_addr
(fra->imgptr, &fra->bpp, &fra->s_l, &fra->endian);
	fra->color1 = 3100000;
}

int		ft_proverka(char *c, t_fractol *fra)
{
	if (ft_strcmp(c, "julia") == 0)
		init_julia(fra);
	else if (ft_strcmp(c, "mandel") == 0)
		init_mandel(fra);
	else if (ft_strcmp(c, "random") == 0)
		init_random(fra);
	else if (ft_strcmp(c, "spiner") == 0)
		init_spiner(fra);
	else
	{
		error();
		ft_exit();
	}
	if (fra->reshaem == 1 || fra->reshaem == 2 ||
		fra->reshaem == 3 || fra->reshaem == 4)
		rehaem(fra);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fractol fra;

	mlx_init_it(&fra);
	if (argc != 2)
	{
		error();
		return (-1);
	}
	else
		ft_proverka(argv[1], &fra);
	mlx_key_hook(fra.win, hook_keydown, &fra);
	mlx_mouse_hook(fra.win, mouse_hook, &fra);
	mlx_loop(fra.mlx);
	return (0);
}

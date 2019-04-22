/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:53:58 by coconroy          #+#    #+#             */
/*   Updated: 2019/03/31 18:50:13 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)src;
	d = (char *)dest;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (d);
}

void	pix_to_img(t_fractol *fra, int color)
{
	fra->color = mlx_get_color_value(fra->mlx, color);
	ft_memmove(fra->imgstr + (4 * (fra->width * fra->y))
			+ (fra->x * 4), &fra->color, sizeof(int));
}

void	bfr_pix(t_fractol *fra)
{
	if (fra->i == fra->itmax)
		pix_to_img(fra, 0);
	else
		pix_to_img(fra, (fra->i * fra->color1));
}

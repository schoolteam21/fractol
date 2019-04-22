/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:53:16 by coconroy          #+#    #+#             */
/*   Updated: 2019/03/31 18:58:47 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	void			*imgptr;
	char			*imgstr;
	int				endian;
	int				s_l;
	int				bpp;
	int				x;
	int				y;
	int				i;
	int				color;
	int				color1;
	double			zoom;
	int				itmax;
	int				width;
	int				height;
	int				reshaem;
	double			q;
	double			z_r;
	double			z_i;
	double			tmp;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			c_r;
	double			c_i;
	int				mov_juju;
}					t_fractol;

void				*ft_memmove(void *dest, const void *src, size_t n);
void				pix_to_img(t_fractol *fra, int color);
void				bfr_pix(t_fractol *fra);
void				init_spiner(t_fractol *fra);
void				exten_spiner(t_fractol *fra);
void				draw_spiner(t_fractol *fra);
void				init_random(t_fractol *fra);
void				exten_random(t_fractol *fra);
void				draw_random(t_fractol *fra);
void				init_julia(t_fractol *fra);
void				mlx_init_it(t_fractol *fra);
int					main(int argc, char **argv);
void				draw_julia(t_fractol *fra);
void				exten_julia(t_fractol *fra);
void				init_julia(t_fractol *fra);
void				init_mandel(t_fractol *fra);
void				exten_mandel(t_fractol *fra);
void				draw_mandel(t_fractol *fra);
int					mouse_juju(int x, int y, t_fractol *fra);
void				zoom(t_fractol *fra, int x, int y);
void				dezoom(t_fractol *fra, int x, int y);
int					mouse_hook(int mousecode, int x, int y, t_fractol *fra);
int					hook_keydown(int key, t_fractol *fra);
void				rehaem(t_fractol *fra);
void				error(void);
void				ft_exit(void);
void				dlya_strelok(t_fractol *fra);

#endif

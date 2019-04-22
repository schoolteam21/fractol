/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:46:56 by coconroy          #+#    #+#             */
/*   Updated: 2019/03/31 18:19:52 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error(void)
{
	write(1, "Vibirite vtoroy parametr\n", 25);
	write(1, "Dlya fractala mandelbrota -> mandel\n", 36);
	write(1, "Dlya fractala julia -> julia\n", 29);
	write(1, "Dlya fractala spiner -> spiner\n", 31);
	write(1, "Dlya fractala randomfractal -> random\n", 38);
}

void	ft_exit(void)
{
	exit(0);
}

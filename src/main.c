/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 17:04:55 by prichard          #+#    #+#             */
/*   Updated: 2016/06/07 11:35:00 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_all	*init_all(t_all *all)
{
	all->img = (t_img*)ft_memalloc(sizeof(t_img));
	all->mlx = (t_mlx*)ft_memalloc(sizeof(t_mlx));
	all->coord = (t_coord*)ft_memalloc(sizeof(t_coord));
	all->fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	return (all);
}

t_mlx	*mlxinit(t_all *all, int width, int height, char *name)
{
	all->mlx->ptr = mlx_init();
	all->mlx->win = mlx_new_window(all->mlx->ptr, width, height, name);
	all->mlx->height = height;
	all->mlx->width = width;
	return (all->mlx);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	t_img	*img;
	t_fract	*fract;
	t_all	*all;

	all = (t_all*)ft_memalloc(sizeof(t_all));
	if (ac == 2)
	{
		all = init_all(all);
		mlx = mlxinit(all, 1000, 1000, "fractol");
		img = set_image(all);
		fract = init_fract_struct(all, av[1]); 
		draw(all);
		/*mlx_put_image_to_window(all->mlx->ptr, all->mlx->win, all->img->ptr, 0, 0);*/
		mlx_hook(all->mlx->win,2, 0,  key_handler, all);// changed from mlx_hook
		mlx_mouse_hook(all->mlx->win, mouse_hook, all);
		mlx_loop(all->mlx->ptr);
		return (0);
	}
	ft_putendl("Not enough or too much arguments. Need 2.");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:21:01 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/08 00:50:22 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	combiencolon(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i + 1);
}

void	mlx_initer(t_var *var)
{
	int	*lel;
	int	lol;

	lol = 0;
	lel = &lol;
	var->larg = combiencolon(var->map);
	var->haut = combienlignes(var->map);
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, (var->larg - 1) * 128,
			var->haut * 128, "gamou");
	var->wimg = mlx_xpm_file_to_image(var->mlx, "buisson.xpm", lel, lel);
	var->pimg = mlx_xpm_file_to_image(var->mlx, "megumin.xpm", lel, lel);
	var->gimg = mlx_xpm_file_to_image(var->mlx, "herb.xpm", lel, lel);
	var->cimg = mlx_xpm_file_to_image(var->mlx, "explosion.xpm", lel, lel);
	var->eimg = mlx_xpm_file_to_image(var->mlx, "kazuma.xpm", lel, lel);
	var->bimg = mlx_xpm_file_to_image(var->mlx, "billboard.xpm", lel, lel);
}

void	caraprint(int x, int y, int i, t_var *var)
{
	if (var->map[i] == '1')
		mlx_put_image_to_window(var->mlx, var->win,
			var->wimg, x * 128, y * 128);
	if (var->map[i] == 'P')
	{
		mlx_put_image_to_window(var->mlx, var->win,
			var->pimg, x * 128, y * 128);
		var->posx = x;
		var->posy = y;
		var->poschar = i;
	}
	if (var->map[i] == 'C')
		mlx_put_image_to_window(var->mlx, var->win,
			var->cimg, x * 128, y * 128);
	if (var->map[i] == 'E')
		mlx_put_image_to_window(var->mlx, var->win,
			var->eimg, x * 128, y * 128);
}

void	map_1st_print(t_var *var)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (x < var->larg)
	{
		while (y <= var->haut)
		{
			mlx_put_image_to_window(var->mlx, var->win,
				var->gimg, x * 128, y * 128);
			y++;
		}
		x++;
		y = 0;
	}
	while (var->map[i] != '\0')
	{
		x = i % var->larg;
		y = i / var->larg;
		caraprint(x, y, i, var);
		i++;
	}
}

int	game(char *map)
{
	t_var	var;

	var.move = 0;
	var.map = map;
	mlx_initer(&var);
	map_1st_print(&var);
	mlx_key_hook(var.win, deal_key, &var);
	mlx_put_image_to_window(var.mlx, var.win, var.bimg, 32, 32);
	mlx_string_put(var.mlx, var.win, 50, 50, 1, "0");
	mlx_string_put(var.mlx, var.win, 50, 60, 1, "move");
	mlx_loop(var.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:33:48 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/08 00:48:01 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	verificator(int key, t_var *var)
{
	if (key == 0)
		printf("lol %d\n", var->posx);
	return (1);
}

void	lessmove(int key, t_var *var)
{
	if (key == 0)
	{
		mlx_put_image_to_window(var->mlx, var->win,
			var->gimg, var->posx * 128, var->posy * 128);
		mlx_put_image_to_window(var->mlx, var->win,
			var->pimg, (var->posx * 128) - 128, var->posy * 128);
		var->posx--;
	}
	else if (key == 2)
	{
		mlx_put_image_to_window(var->mlx, var->win,
			var->gimg, var->posx * 128, var->posy * 128);
		mlx_put_image_to_window(var->mlx, var->win,
			var->pimg, (var->posx * 128) + 128, var->posy * 128);
		var->posx++;
	}
}

void	lessmove2(int key, t_var *var)
{
	if (key == 13)
	{
		mlx_put_image_to_window(var->mlx, var->win,
			var->gimg, var->posx * 128, var->posy * 128);
		mlx_put_image_to_window(var->mlx, var->win,
			var->pimg, var->posx * 128, (var->posy * 128) - 128);
		var->posy--;
	}
	else if (key == 1)
	{
		mlx_put_image_to_window(var->mlx, var->win,
			var->gimg, var->posx * 128, var->posy * 128);
		mlx_put_image_to_window(var->mlx, var->win,
			var->pimg, var->posx * 128, (var->posy * 128) + 128);
		var->posy++;
	}
}

int	deal_key(int key, t_var *var)
{
	int	verif;

	verif = verificator(key, var);
	if (verif)
	{
		lessmove(key, var);
		lessmove2(key, var);
		printf("%d moves\n", ++var->move);
		var->moves = ft_itoa(var->move);
		mlx_put_image_to_window(var->mlx, var->win, var->bimg, 32, 32);
		mlx_string_put(var->mlx, var->win, 50, 50, 1, var->moves);
		mlx_string_put(var->mlx, var->win, 50, 60, 1, "moves");
	}
	if (key == 53)
	{
		printf("#FinDuGameLEL\n");
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	return (0);
}

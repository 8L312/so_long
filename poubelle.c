/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poubelle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:03:37 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/09 17:32:49 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	exiter(t_var *var)
{
	printf("#FinDuGameLEL\n");
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
	return (0);
}

int	oneplayeronly(char *map)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (map[i++] != '\0')
	{
		if (map[i] == 'P')
			p++;
	}
	if (p > 1)
	{
		printf("Error\n( ° ͜ʖ͡°)╭∩╮C'est un jeu solo mekk\n");
		return (0);
	}
	return (1);
}

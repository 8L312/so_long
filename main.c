/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:16:43 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/03 17:43:17 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*map;

	(void) argc;
	(void) argv;
	if (argc != 2)
	{
		printf("Error\nInvalid arguments\n");
		return (-1);
	}
	map = mapverif(argv[1]);
	if (!map)
	{
		printf("Error\nInvalid map\n");
		return (-1);
	}
	else
		game(map);
	return (1);
}

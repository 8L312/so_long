/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:16:43 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/09 17:13:48 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*map;

	if (argc != 2)
	{
		printf("Error\n2 arguemnts : so_long et ta map ╭∩╮(･◡･)╭∩╮\n");
		return (-1);
	}
	map = mapverif(argv[1]);
	if (!map)
		return (-1);
	else
		game(map);
	return (1);
}

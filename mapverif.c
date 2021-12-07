/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapverif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:33:49 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/07 19:33:18 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	mapisber(char *mapfile)
{
	int	i;

	i = 0;
	while (mapfile[i] != '\0')
		i++;
	i--;
	if (mapfile[i--] != 'r')
		return (0);
	if (mapfile[i--] != 'e')
		return (0);
	if (mapfile[i--] != 'b')
		return (0);
	if (mapfile[i] != '.')
		return (0);
	return (1);
}

int	maprectangle(char *map)
{
	char	**split;
	int		i;
	size_t	len;

	i = 0;
	split = ft_split(map, '\n');
	len = ft_strlen(split[i]);
	while (split[i] != NULL)
	{
		if (len != ft_strlen(split[i]))
			return (0);
		i++;
	}
	return (1);
}

int	mapfullmur(char *map)
{
	char	**split;
	size_t	len;
	size_t	j;
	size_t	a;

	j = 0;
	a = combienlignes(map);
	split = ft_split(map, '\n');
	len = ft_strlen(split[0]) - 1;
	while (split[0][j] == '1')
		j++;
	if ((j - 1) != len)
		return (0);
	j = 1;
	while (j++ != a - 1)
		if (split[j][0] != '1' || split[j][len] != '1')
			return (0);
	j = 0;
	while (split[a - 1][j] == '1')
		j++;
	if ((j - 1) != len)
		return (0);
	return (1);
}

int	characheck(char *map)
{
	int	i;

	i = 0;
	while (map[i++] != '\0')
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P' && map[i] != 'C'
			&& map[i] != 'E' && map[i] != '\n' && map[i] != '\0')
			return (0);
	return (1);
}

char	*mapverif(char *mapfile)
{
	int		fd;
	char	*map;

	map = NULL;
	if (!mapisber(mapfile))
		return (NULL);
	fd = open((const char *)mapfile, O_RDONLY);
	map = get_next_line(fd);
	if (!maprectangle(map))
		return (NULL);
	if (!mapfullmur(map))
		return (NULL);
	if (!characheck(map))
		return (NULL);
	return (map);
}

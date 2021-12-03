/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:28:00 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/03 18:40:26 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
#include <stddef.h>
# include "mlx.h"

typedef struct s_var {
	void	*mlx;
	void	*win;
	void	*wimg;
	void	*pimg;
	void	*fimg;
	void	*cimg;
	int		posx;
	int		posy;
	int		move;
}				t_var;

int		main(int argc, char **argv);
char	*mapverif(char *mapfile);
int		mapisber(char *mapfile);

#endif

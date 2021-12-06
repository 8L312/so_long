/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:28:00 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/06 21:14:32 by rmonney          ###   ########.fr       */
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
# include <stddef.h>
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

# define BUFFER_SIZE  1

int		main(int argc, char **argv);
char	*mapverif(char *mapfile);
int		mapisber(char *mapfile);
int		maprectangle(char *map);
int		mapfullmur(char *map);
char	*readsave(int fd, char *save);
char	*get_line(char *save);
char	*rest(char *save);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *save, char *buff);
int		ft_strchr(char *s, int c);
char	**ft_split(char const *s, char c);
char	**spliter(char **split, char const *s, char c);
char	*word_dup(char *str, int start, int finish);
int		word_counter(char *str, char c);
size_t	combienlignes(char *map);

#endif

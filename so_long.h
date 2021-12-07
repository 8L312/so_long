/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:28:00 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/08 00:49:34 by rmonney          ###   ########.fr       */
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
# include "./minilibx/mlx.h"

typedef struct s_var {
	void	*mlx;
	void	*win;
	void	*wimg;
	void	*pimg;
	void	*gimg;
	void	*cimg;
	void	*eimg;
	void	*bimg;
	int		posx;
	int		posy;
	int		poschar;
	int		larg;
	int		haut;
	int		move;
	char	*moves;
	char	*map;
}				t_var;

# define BUFFER_SIZE  999

int			main(int argc, char **argv);
char		*mapverif(char *mapfile);
int			mapisber(char *mapfile);
int			maprectangle(char *map);
int			mapfullmur(char *map);
char		*readsave(int fd, char *save);
char		*get_line(char *save);
char		*rest(char *save);
char		*get_next_line(int fd);
size_t		ft_strlen(char *str);
char		*ft_strjoin(char *save, char *buff);
int			ft_strchr(char *s, int c);
char		**ft_split(char const *s, char c);
char		**spliter(char **split, char const *s, char c);
char		*word_dup(char *str, int start, int finish);
int			word_counter(char *str, char c);
size_t		combienlignes(char *map);
int			game(char *map);
int			combiencolon(char *map);
void		mlx_initer(t_var *var);
void		map_1st_print(t_var *var);
void		caraprint(int x, int y, int i, t_var *var);
int			deal_key(int key, t_var *var);
int			verificator(int key, t_var *var);
char		*ft_itoa(int n);
char		*writer(char *s, int a, int i, long int nc);
long int	power(long int nb, int pow);
long int	caracounter(long int n);
void		lessmove(int key, t_var *var);
void		lessmove2(int key, t_var *var);

#endif

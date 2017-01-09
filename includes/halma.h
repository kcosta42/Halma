/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halma.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 23:01:26 by kcosta            #+#    #+#             */
/*   Updated: 2016/12/29 16:09:32 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HALMA_F
# define HALMA_F

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define FLUSH() for (int c;(c = getchar()) != '\n' && c != EOF;);
# define RED "\033[91m"
# define BLUE "\033[34m"
# define EOC "\033[39m"

typedef struct	s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct	s_player
{
	t_vector	*pion;
	int			ia;
}				t_player;

extern t_vector	previous_jump;

void			gotoligcol(t_vector pos);
int				display_menu(void);
void			blink_pion(int nb_player, t_player **player,
											t_vector pion_selected, int redo);
void			display_grid(int nb_player, t_player **player);
t_player		**initialise_player(int nb_player);
int				play(int nb_player, int current_player, t_player **player);
int				check_win(int nb_player, t_player **player);

#endif

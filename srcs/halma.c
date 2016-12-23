/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halma.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 22:52:48 by kcosta            #+#    #+#             */
/*   Updated: 2016/12/20 20:39:45 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/halma.h"

t_vector	previous_jump = {-1, -1};

int		main(void)
{
	t_vector	cursor_pos;
	int			nb_player;
	t_player	**player;
	int			winner;

	winner = -1;
	cursor_pos.x = 0;
	cursor_pos.y = 20;
	nb_player = display_menu();
	player = initialise_player(nb_player);
	while (1)
	{
		for (int i = 0; i < nb_player; i++)
		{
			winner = play(nb_player, i, player);
			printf("%d\n", winner);
		}
	}
}

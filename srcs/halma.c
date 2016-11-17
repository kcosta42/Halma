/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halma.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 22:52:48 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/17 14:11:41 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/halma.h"

int		main(void)
{
	t_vector	cursor_pos;
	int			nb_player;
	t_player	**player;

	cursor_pos.x = 0;
	cursor_pos.y = 20;
	nb_player = display_menu();
	player = initialise_player(nb_player);
	while (1)
	{
		for (int i = 0; i < nb_player; i++)
		{
			play(nb_player, i, player);
		}
	}
}

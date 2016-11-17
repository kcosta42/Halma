/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:41:21 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/17 13:20:52 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/halma.h"

void		initialise_p1(int nb_player, t_player **player);
void		initialise_p2(int nb_player, t_player **player);
void		initialise_p3(int nb_player, t_player **player);
void		initialise_p4(int nb_player, t_player **player);

void	(*initialise[4])(int, t_player**) = {&initialise_p1, &initialise_p2,
											&initialise_p3, &initialise_p4};

t_player	**initialise_player(int nb_player)
{
	t_player	**player;
	int			i;
	int			max_pion;

	i = 0;
	max_pion = (nb_player == 2) ? 19 : 13;
	player = (t_player**)malloc(sizeof(t_player*) * nb_player);
	while (i < nb_player)
	{
		player[i] = (t_player*)malloc(sizeof(t_player));
		player[i]->pion = (t_vector*)malloc(sizeof(t_vector) * max_pion);
		initialise[i](nb_player, player);
		i++;
	}
	return (player);
}

void		initialise_p1(int nb_player, t_player **player)
{
	t_vector	pos;
	t_vector	max;
	int			i;

	i = 0;
	pos.y = 0;
	max.x = (nb_player == 2) ? 5 : 4;
	max.y = (nb_player == 2) ? 5 : 4;
	while (pos.y < max.y)
	{
		pos.x = 0;
		if (pos.y > 1)
			max.x--;
		while (pos.x < max.x)
		{
			player[0]->pion[i] = pos;
			pos.x++;
			i++;
		}
		pos.y++;
	}
}

void		initialise_p2(int nb_player, t_player **player)
{
	t_vector	pos;
	t_vector	max;
	int			i;

	i = 0;
	pos.y = 15;
	max.x = (nb_player == 2) ? 5 : 4;
	max.y = (nb_player == 2) ? 5 : 4;
	while (pos.y > 15 - max.y)
	{
		pos.x = 15;
		if (pos.y < 14)
			max.x--;
		while (pos.x > 15 - max.x)
		{
			player[1]->pion[i] = pos;
			pos.x--;
			i++;
		}
		pos.y--;
	}
}

void		initialise_p3(int nb_player, t_player **player)
{
	t_vector	pos;
	t_vector	max;
	int			i;

	(void)nb_player;
	i = 0;
	pos.y = 0;
	max.x = 4;
	max.y = 4;
	while (pos.y < max.y)
	{
		pos.x = 15;
		if (pos.y > 1)
			max.x--;
		while (pos.x > 15 - max.x)
		{
			player[2]->pion[i] = pos;
			pos.x--;
			i++;
		}
		pos.y++;
	}
}

void		initialise_p4(int nb_player, t_player **player)
{
	t_vector	pos;
	t_vector	max;
	int			i;

	(void)nb_player;
	i = 0;
	pos.y = 15;
	max.x = 4;
	max.y = 4;
	while (pos.y > 15 - max.y)
	{
		pos.x = 0;
		if (pos.y < 14)
			max.x--;
		while (pos.x < max.x)
		{
			player[3]->pion[i] = pos;
			pos.x++;
			i++;
		}
		pos.y--;
	}
}

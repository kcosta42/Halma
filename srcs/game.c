/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:21:13 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/17 15:09:23 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/halma.h"

int			is_valid_move(int i)
{
	return ((i >= 0 && i <= 16));
}

int			correct_pion(int nb_player, t_player *player, t_vector pos)
{
	for (int i = (nb_player == 2) ? 18 : 12; i >= 0; i--)
	{
		if (player->pion[i].x == pos.x && player->pion[i].y == pos.y)
			return (i);
	}
	return (-1);
}

t_vector	move_pion(t_vector pion_coor, t_vector next_coor)
{
	pion_coor.x = next_coor.x;
	pion_coor.y = next_coor.y;
	return (pion_coor);
}

t_vector		get_move(void)
{
	t_vector	pos;

	pos.x = -1;
	pos.y = -1;
	while (!is_valid_move(pos.x))
	{
		printf("Enter valid coordinate for X:\n");
		//scanf("%d", &pos.x);
		pos.x = getchar();
		if (pos.x >= 'a')
			pos.x = pos.x - 'a' + 10;
		else
			pos.x = pos.x - '0';
		FLUSH();
	}
	while (!is_valid_move(pos.y))
	{
		printf("Enter valid coordinate for Y:\n");
		//scanf("%d", &pos.y);
		pos.y = getchar();
		if (pos.y >= 'a')
			pos.y = pos.y - 'a' + 10;
		else
			pos.y = pos.y - '0';
		FLUSH();
	}
	return (pos);
}

int		replay(int nb_player, int current_player, t_player **player)
{
	int			replay;
	t_vector	cursor_pos;
	
	cursor_pos.x = 0;
	cursor_pos.y = 20;
	system("clear");
	display_grid(nb_player, player);
	gotoligcol(cursor_pos);
	printf("[Player %d turn]\n", current_player + 1);
	printf("Enter anything to play or 0 to pass\n");
	//scanf("%d", &replay);
	replay = getchar();
	replay -= '0';
	FLUSH();
	return (replay);
}

void	play(int nb_player, int current_player, t_player **player)
{
	t_vector	pion_coor;
	t_vector	next_coor;
	int			current;

	while (replay(nb_player, current_player, player))
	{
		current = -1;
		pion_coor.x = -1;
		pion_coor.y = -1;
		printf("Choose which pion to move:\n");
		while ((current = correct_pion(nb_player, player[current_player], pion_coor)) < 0)
			pion_coor = get_move();
		printf("Choose where to move:\n");
		next_coor = get_move();
		player[current_player]->pion[current] = move_pion(pion_coor, next_coor);
	}
}

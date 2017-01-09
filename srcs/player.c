/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:41:21 by kcosta            #+#    #+#             */
/*   Updated: 2016/12/29 16:09:35 by kcosta           ###   ########.fr       */
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

	player[0]->ia = -1;
	printf("Enable Player One auto ?\nYes - 1\nNo - 0\n");
	while (player[0]->ia != 0 && player[0]->ia != 1)
	{
		if (player[0]->ia != -1)
			printf("%sInvalid Entry\n%s", RED, EOC);
		player[0]->ia = getchar();
		player[0]->ia -= '0';
		FLUSH();
	}
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

	player[1]->ia = -1;
	printf("Enable Player Two auto ?\nYes - 1\nNo - 0\n");
	while (player[1]->ia != 0 && player[1]->ia != 1)
	{
		if (player[1]->ia != -1)
			printf("%sInvalid Entry\n%s", RED, EOC);
		player[1]->ia = getchar();
		player[1]->ia -= '0';
		FLUSH();
	}
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

	player[2]->ia = -1;
	printf("Enable Player Three auto ?\nYes - 1\nNo - 0\n");
	while (player[2]->ia != 0 && player[2]->ia != 1)
	{
		if (player[2]->ia != -1)
			printf("%sInvalid Entry\n%s", RED, EOC);
		player[2]->ia = getchar();
		player[2]->ia -= '0';
		FLUSH();
	}
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

	player[3]->ia = -1;
	printf("Enable Player Four auto ?\nYes - 1\nNo - 0\n");
	while (player[3]->ia != 0 && player[3]->ia != 1)
	{
		if (player[3]->ia != -1)
			printf("%sInvalid Entry\n%s", RED, EOC);
		player[3]->ia = getchar();
		player[3]->ia -= '0';
		FLUSH();
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:29:38 by kcosta            #+#    #+#             */
/*   Updated: 2016/12/29 15:48:24 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/halma.h"

int		check_p1(int nb_player, t_player *player);
int		check_p2(int nb_player, t_player *player);
int		check_p3(int nb_player, t_player *player);
int		check_p4(int nb_player, t_player *player);

int		(*check[4])(int, t_player*) = {&check_p1, &check_p2,
										&check_p3, &check_p4};

int		check_win(int nb_player, t_player **player)
{
	for (int i = 0; i < nb_player; i++)
	{
		if (check[i](nb_player, player[i]))
			return (i);
	}
	return (-1);
}

int		check_p2(int nb_player, t_player *player)
{
	t_vector	pos;
	t_vector	max;
	int			ret;

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
			ret = 1;
			for (int i = (nb_player == 2) ? 18 : 12; i >= 0; i--)
			{
				if (player->pion[i].x == pos.x && player->pion[i].y == pos.y)
					ret = 0;
			}
			if (ret)
				return (0);
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}

int			check_p1(int nb_player, t_player *player)
{
	t_vector	pos;
	t_vector	max;
	int			ret;

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
			ret = 1;
			for (int i = (nb_player == 2) ? 18 : 12; i >= 0; i--)
			{
				if (player->pion[i].x == pos.x && player->pion[i].y == pos.y)
					ret = 0;
			}
			if (ret)
				return (0);
			pos.x--;
		}
		pos.y--;
	}
	return (1);
}

int			check_p4(int nb_player, t_player *player)
{
	t_vector	pos;
	t_vector	max;
	int			ret;

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
			ret = 1;
			for (int i = (nb_player == 2) ? 18 : 12; i >= 0; i--)
			{
				if (player->pion[i].x == pos.x && player->pion[i].y == pos.y)
					ret = 0;
			}
			if (ret)
				return (0);
			pos.x--;
		}
		pos.y++;
	}
	return (1);
}

int			check_p3(int nb_player, t_player *player)
{
	t_vector	pos;
	t_vector	max;
	int			ret;

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
			ret = 1;
			for (int i = (nb_player == 2) ? 18 : 12; i >= 0; i--)
			{
				if (player->pion[i].x == pos.x && player->pion[i].y == pos.y)
					ret = 0;
			}
			if (ret)
				return (0);
			pos.x++;
		}
		pos.y--;
	}
	return (1);
}

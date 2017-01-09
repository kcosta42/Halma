/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:21:13 by kcosta            #+#    #+#             */
/*   Updated: 2016/12/30 22:00:55 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/halma.h"

# define HEX "0123456789abcdef"

int			replay;
int			first_move;
int			rejump = 0;
int			limit;

unsigned int rand_interval(unsigned int min, unsigned int max)
{
	int r;
	const unsigned int range = 1 + max - min;
	const unsigned int buckets = RAND_MAX / range;
	const unsigned int limit = buckets * range;

	do
	{
		r = rand();
	} while (r >= (int)limit);

	return min + (r / buckets);
}

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

int			near_coor_ia(int current_player, t_vector pion_coor, t_vector next_coor)
{
	return ((next_coor.x == pion_coor.x + 1 && next_coor.y == pion_coor.y && (current_player == 0 || current_player == 3)) ||
			(next_coor.x == pion_coor.x + 1 && next_coor.y == pion_coor.y + 1 && (current_player == 0 || current_player == 2 || current_player == 3)) ||
			(next_coor.x == pion_coor.x && next_coor.y == pion_coor.y + 1 && (current_player == 0 || current_player == 2)) ||
			(next_coor.x == pion_coor.x - 1 && next_coor.y == pion_coor.y + 1 && (current_player == 0 || current_player == 1 || current_player == 2)) ||
			(next_coor.x == pion_coor.x - 1 && next_coor.y == pion_coor.y && (current_player == 1 || current_player == 2)) ||
			(next_coor.x == pion_coor.x - 1 && next_coor.y == pion_coor.y - 1 && (current_player == 1 || current_player == 2 || current_player == 3)) ||
			(next_coor.x == pion_coor.x && next_coor.y == pion_coor.y - 1 && (current_player == 1 || current_player == 3)) ||
			(next_coor.x == pion_coor.x + 1 && next_coor.y == pion_coor.y - 1 && (current_player == 0 || current_player == 1 || current_player == 3)));
}

int			jump_coor_ia(int current_player, int nb_player, t_player **player, t_vector pion_coor, t_vector next_coor)
{
	int			jump;
	t_vector	index;

	index.x = 0;
	jump = 0;
	while (index.x < nb_player)
	{
		index.y = (nb_player == 2) ? 18 : 12;
		while (index.y >= 0)
		{
			if ((next_coor.x == pion_coor.x + 2 && next_coor.y == pion_coor.y && next_coor.x == player[index.x]->pion[index.y].x + 1 && next_coor.y == player[index.x]->pion[index.y].y && (current_player == 0 || current_player == 3)) ||
					(next_coor.x == pion_coor.x + 2 && next_coor.y == pion_coor.y + 2 && next_coor.x == player[index.x]->pion[index.y].x + 1 && next_coor.y == player[index.x]->pion[index.y].y + 1 && (current_player == 0 || current_player == 2 || current_player == 3)) ||
					(next_coor.x == pion_coor.x && next_coor.y == pion_coor.y + 2 && next_coor.x == player[index.x]->pion[index.y].x && next_coor.y == player[index.x]->pion[index.y].y + 1 && (current_player == 0 || current_player == 2)) ||
					(next_coor.x == pion_coor.x - 2 && next_coor.y == pion_coor.y + 2 && next_coor.x == player[index.x]->pion[index.y].x - 1 && next_coor.y == player[index.x]->pion[index.y].y + 1 && (current_player == 0 || current_player == 1 || current_player == 2)) ||
					(next_coor.x == pion_coor.x - 2 && next_coor.y == pion_coor.y && next_coor.x == player[index.x]->pion[index.y].x - 1 && next_coor.y == player[index.x]->pion[index.y].y && (current_player == 1 || current_player == 2)) ||
					(next_coor.x == pion_coor.x - 2 && next_coor.y == pion_coor.y - 2 && next_coor.x == player[index.x]->pion[index.y].x - 1 && next_coor.y == player[index.x]->pion[index.y].y - 1 && (current_player == 1 || current_player == 2 || current_player == 3)) ||
					(next_coor.x == pion_coor.x && next_coor.y == pion_coor.y - 2 && next_coor.x == player[index.x]->pion[index.y].x && next_coor.y == player[index.x]->pion[index.y].y - 1 && (current_player == 1 || current_player == 3)) ||
					(next_coor.x == pion_coor.x + 2 && next_coor.y == pion_coor.y - 2 && next_coor.x == player[index.x]->pion[index.y].x + 1 && next_coor.y == player[index.x]->pion[index.y].y - 1 && (current_player == 0 || current_player == 1 || current_player == 3)))
				jump = 1;
			index.y--;
		}
		index.x++;
	}
	rejump = jump;
	return (jump);
}

int			near_coor(t_vector pion_coor, t_vector next_coor)
{
	return ((next_coor.x == pion_coor.x + 1 && next_coor.y == pion_coor.y) ||
			(next_coor.x == pion_coor.x + 1 && next_coor.y == pion_coor.y + 1) ||
			(next_coor.x == pion_coor.x && next_coor.y == pion_coor.y + 1) ||
			(next_coor.x == pion_coor.x - 1 && next_coor.y == pion_coor.y + 1) ||
			(next_coor.x == pion_coor.x - 1 && next_coor.y == pion_coor.y) ||
			(next_coor.x == pion_coor.x - 1 && next_coor.y == pion_coor.y - 1) ||
			(next_coor.x == pion_coor.x && next_coor.y == pion_coor.y - 1) ||
			(next_coor.x == pion_coor.x + 1 && next_coor.y == pion_coor.y - 1));
}

int			jump_coor(int nb_player, t_player **player, t_vector pion_coor, t_vector next_coor)
{
	int			jump;
	t_vector	index;

	index.x = 0;
	jump = 0;
	while (index.x < nb_player)
	{
		index.y = (nb_player == 2) ? 18 : 12;
		while (index.y >= 0)
		{
			if ((next_coor.x == pion_coor.x + 2 && next_coor.y == pion_coor.y && next_coor.x == player[index.x]->pion[index.y].x + 1 && next_coor.y == player[index.x]->pion[index.y].y) ||
					(next_coor.x == pion_coor.x + 2 && next_coor.y == pion_coor.y + 2 && next_coor.x == player[index.x]->pion[index.y].x + 1 && next_coor.y == player[index.x]->pion[index.y].y + 1) ||
					(next_coor.x == pion_coor.x && next_coor.y == pion_coor.y + 2 && next_coor.x == player[index.x]->pion[index.y].x && next_coor.y == player[index.x]->pion[index.y].y + 1) ||
					(next_coor.x == pion_coor.x - 2 && next_coor.y == pion_coor.y + 2 && next_coor.x == player[index.x]->pion[index.y].x - 1 && next_coor.y == player[index.x]->pion[index.y].y + 1) ||
					(next_coor.x == pion_coor.x - 2 && next_coor.y == pion_coor.y && next_coor.x == player[index.x]->pion[index.y].x - 1 && next_coor.y == player[index.x]->pion[index.y].y) ||
					(next_coor.x == pion_coor.x - 2 && next_coor.y == pion_coor.y - 2 && next_coor.x == player[index.x]->pion[index.y].x - 1 && next_coor.y == player[index.x]->pion[index.y].y - 1) ||
					(next_coor.x == pion_coor.x && next_coor.y == pion_coor.y - 2 && next_coor.x == player[index.x]->pion[index.y].x && next_coor.y == player[index.x]->pion[index.y].y - 1) ||
					(next_coor.x == pion_coor.x + 2 && next_coor.y == pion_coor.y - 2 && next_coor.x == player[index.x]->pion[index.y].x + 1 && next_coor.y == player[index.x]->pion[index.y].y - 1))
				jump = 1;
			index.y--;
		}
		index.x++;
	}
	rejump = jump;
	return (jump);
}

t_vector	move_pion(int current_player, int nb_player, t_player **player, t_vector pion_coor, t_vector next_coor)
{
	t_vector	index;

	index.x = 0;
	if (player[current_player]->ia)
	{
		if (rejump && !(pion_coor.x == previous_jump.x && pion_coor.y == previous_jump.y))
			return (pion_coor);
		if (rejump || !near_coor_ia(current_player, pion_coor, next_coor))
			if (!jump_coor_ia(current_player, nb_player, player, pion_coor, next_coor))
				return (pion_coor);
	}
	else
	{
		if (rejump && !(pion_coor.x == previous_jump.x && pion_coor.y == previous_jump.y))
			return (pion_coor);
		if (rejump || !near_coor(pion_coor, next_coor))
			if (!jump_coor(nb_player, player, pion_coor, next_coor))
				return (pion_coor);
	}
	while (index.x < nb_player)
	{
		index.y = (nb_player == 2) ? 18 : 12;
		while (index.y >= 0)
		{
			if (player[index.x]->pion[index.y].x == next_coor.x &&
					player[index.x]->pion[index.y].y == next_coor.y)
				return (pion_coor);
			index.y--;
		}
		index.x++;
	}
	pion_coor.x = next_coor.x;
	pion_coor.y = next_coor.y;
	return (pion_coor);
}

t_vector		get_move(int ia)
{
	t_vector	pos;

	pos.x = -1;
	pos.y = -1;
	while (!is_valid_move(pos.x))
	{
		if (!ia)
			printf("Enter valid coordinate for X:\n");
		//scanf("%d", &pos.x);
		if (ia)
			pos.x = HEX[rand_interval(0, 15)];
		else
		{
			pos.x = getchar();
			FLUSH();
		}
		if (pos.x >= 'a')
			pos.x = pos.x - 'a' + 10;
		else
			pos.x = pos.x - '0';
	}
	while (!is_valid_move(pos.y))
	{
		if (!ia)
			printf("Enter valid coordinate for Y:\n");
		//scanf("%d", &pos.y);
		if (ia)
			pos.y = HEX[rand_interval(0, 15)];
		else
		{
			pos.y = getchar();
			FLUSH();
		}
		if (pos.y >= 'a')
			pos.y = pos.y - 'a' + 10;
		else
			pos.y = pos.y - '0';
	}
	return (pos);
}

int		player_replay(int nb_player, int current_player, t_player **player)
{
	t_vector	cursor_pos;

	cursor_pos.x = 0;
	cursor_pos.y = 20;
	system("clear");
	display_grid(nb_player, player);
	gotoligcol(cursor_pos);
	printf("[Player %d turn]\n", current_player + 1);
	if	(!first_move)
		return (1);
	if (rejump)
		replay = 0;
	if (replay == -1)
		if (!player[current_player]->ia)
			printf("%sInvalid Move%s\n", RED, EOC);
	//scanf("%d", &replay);
	if (!replay && !player[current_player]->ia)
	{
		printf("Enter anything to play or 0 to pass\n");
		replay = getchar();
		replay -= '0';
		FLUSH();
	}
	return (replay);
}

int		play(int nb_player, int current_player, t_player **player)
{
	t_vector	pion_coor;
	t_vector	next_coor;
	t_vector	tmp;
	int			current;

	first_move = 0;
	limit = 0;
	while (player_replay(nb_player, current_player, player))
	{
		limit++;
		if (limit > 5000)
			return (-1);
		current = -1;
		pion_coor.x = -1;
		pion_coor.y = -1;
		printf("Choose which pion to move:\n");
		while ((current = correct_pion(nb_player, player[current_player], pion_coor)) < 0)
		{
			if (!rejump && first_move && !player[current_player]->ia)
				printf("%sInvalid coordinate%s\n", RED, EOC);
			pion_coor = get_move(player[current_player]->ia);
			if (!first_move++)
				previous_jump = pion_coor;
		}
		printf("Choose where to move:\n");
		next_coor = get_move(player[current_player]->ia);
		tmp = move_pion(current_player, nb_player, player, pion_coor, next_coor);
		if (tmp.x == player[current_player]->pion[current].x &&
				tmp.y == player[current_player]->pion[current].y)
		{
			replay = -1;
			rejump = 0;
		}
		else
		{
//			blink_pion(nb_player, player, player[current_player]->pion[current],
//						(player[current_player]->ia) ? 8 : 0);
			player[current_player]->pion[current] = tmp;
			previous_jump = tmp;
//			blink_pion(nb_player, player, player[current_player]->pion[current],
//						(player[current_player]->ia) ? 4 : 0);
			if (!rejump)
				return (check_win(nb_player, player));
		}
	}
	rejump = 0;
	return (check_win(nb_player, player));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 23:19:04 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/17 14:26:06 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/halma.h"

void		gotoligcol(t_vector pos)
{
	printf("\033[%d;%dH", (pos.y), (pos.x));
}

void		display_grid(int nb_player, t_player **player)
{
	t_vector	pos;
	char		hex[16] = "0123456789abcdef";
	char		current;

	pos.y = 0;
	printf("  X  0 1 2 3 4 5 6 7 8 9 a b c d e f\n");
	printf("Y                                   \n");
	while (pos.y < 16)
	{
		pos.x = 0;
		printf("%c   ", hex[pos.y]);
		while (pos.x < 16)
		{
			current = '.';
			for (int i = 0; i < nb_player; i++)
			{
				for (int j = (nb_player == 2) ? 18 : 12; j >= 0; j--)
				{
					if (player[i]->pion[j].x == pos.x &&
						player[i]->pion[j].y == pos.y)
						current = 'A' + i;
				}
			}
			printf(" %c", current);
			pos.x++;
		}
		printf("\n");
		pos.y++;
	}
}
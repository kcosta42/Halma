/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:21:48 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/17 15:06:30 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/halma.h"

int		display_menu(void)
{
	int		nb_player;

	nb_player = 0;
	system("clear");
	printf("\n");
	printf("\n");
	printf("  ##  ##       ##     ##       ##     ##        ##\n");
	printf("  ##  ##     ##  ##   ##      ## ## ## ##     ##  ##\n");
	printf("  ######    ##   ##   ##      ##   ##  ##    ##   ##\n");
	printf("  ##  ##   ## ### ##  ##      ##       ##   ## ### ##\n");
	printf("  ##  ##  ##      ##  ######  ##       ##  ##      ##\n");
	printf("\n");
	printf("\n");
	printf("Choose number of player (2 or 4): \n");
	while (nb_player != 2 && nb_player != 4)
	{
		//scanf("%d", &nb_player);
		nb_player = getchar();
		nb_player -= '0';
		FLUSH();
	}
	return (nb_player);
}

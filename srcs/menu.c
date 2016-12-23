/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:21:48 by kcosta            #+#    #+#             */
/*   Updated: 2016/12/20 22:15:47 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/halma.h"

int		display_menu(void)
{
	int		nb_player;

	nb_player = 0;
	system("clear");
	printf("\n\n");
	printf("   / / / /   |  / /   /  |/  /   |\n");
	printf("  / /_/ / /| | / /   / /|_/ / /| |\n");
	printf(" / __  / ___ |/ /___/ /  / / ___ |\n");
	printf("/_/ /_/_/  |_/_____/_/  /_/_/  |_|\n");
	printf("\n\n");
	printf("Choose number of player (2 to 4): \n");
	while (nb_player < 2 || nb_player > 4)
	{
		//scanf("%d", &nb_player);
		nb_player = getchar();
		nb_player -= '0';
		FLUSH();
	}
	return (nb_player);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 18:01:24 by bvilla            #+#    #+#             */
/*   Updated: 2019/06/14 18:45:28 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap_players(struct s_player **a, struct s_player **b){
    struct s_player *tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort(struct s_player **players){
    if (!players || !*players)
        return ;
    for(int i = 1; players[i]; i++)
    {
        for (int j = i - 1; j >= 0; j--)
            if (players[j]->score < players[j + 1]->score)
                swap_players(players + j, players + j + 1);
    }
}

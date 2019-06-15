/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 19:45:10 by victor            #+#    #+#             */
/*   Updated: 2019/06/14 21:01:57 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <time.h>

void swap_players(struct s_player **a, struct s_player **b){
    struct s_player *tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int     partition(struct s_player **players, int lo, int hi){
    int     p = (rand() % (hi - lo + 1)) + lo;
    struct s_player *pp = players[p];
    while (1)
    {
        while (players[lo]->score > pp->score)
            lo++;
        while (players[hi]->score < pp->score)
            hi--;
        if (lo >= hi)
            return (hi);
        swap_players(players + hi, players + lo);
        lo++;
        hi--;
    }
}

void    gen_quicksort(struct s_player **players, int lo, int hi){
    if (lo < hi)
    {
        int p = partition(players, lo, hi);
        gen_quicksort(players, lo, p);
        gen_quicksort(players, p + 1, hi);
    }
}

void quickSort(struct s_player **players){
    int     len;
    static int  seed = 0;
    if (!seed)
    {
        srand(clock());
        seed = 1;
    }
    for(len = 0; players[len]; len++);
    gen_quicksort(players, 0, len - 1);
}
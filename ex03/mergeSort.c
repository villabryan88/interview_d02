/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 21:19:24 by victor            #+#    #+#             */
/*   Updated: 2019/06/14 21:56:33 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap_players(struct s_player **a, struct s_player **b){
    struct s_player *tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    gen_mergesort(struct s_player **players, int lo, int hi, struct s_player **aux){
    int mid;
    if (hi - lo == 0)
        return;
    mid = (hi - lo + 1) / 2 + lo;
    gen_mergesort(aux, lo, mid - 1, players);
    gen_mergesort(aux, mid, hi, players);
    int j = mid;
    for (int i = lo; i <= hi; i++)
    {
        if (j > hi || (lo < mid && aux[lo]->score >= aux[j]->score))
            players[i] = aux[lo++]->score;
        else
            players[i] = aux[j++]->score;
    }
}

struct s_player **mergeSort(struct s_player **players){
    int     len;
    struct s_player **aux;

    for(len = 0; players[len]; len++);
    aux = malloc(sizeof(struct s_player*) * (len + 1));
    memcpy(aux, players, sizeof(struct s_player*) * len);
    aux[len] = 0;
    gen_mergesort(players, 0, len - 1, aux);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 19:45:10 by victor            #+#    #+#             */
/*   Updated: 2019/06/14 20:06:46 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <stdlib.h>
#include <time.h>

void    gen_quicksort(struct s_player **players, int lo, int hi){
    int p = partition(players, lo, hi);
    if (lo < hi)
    {
        gen_quicksort(players, lo, p - 1);
        gen_quicksort(players, p + 1, hi);
    }
}

void quickSort(struct s_player **players){
    int     len;

    for(len = 0; players[len]; len++);

    gen_quicksort(players, 0, len - 1);
}
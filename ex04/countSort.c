/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 22:28:59 by victor            #+#    #+#             */
/*   Updated: 2019/06/14 23:04:48 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "header.h"
#include <stdlib.h>

int  get_max(unsigend char *untensils, int n){
    int max = 0;
    for (int i = 0; i < n; i++)
        if(utensils[i] > n )
            max = utensils[i];
}

void countSort(unsigned char *utensils, int n){
    unsigned char *copy = malloc(sizeof(n));
    int max = get_max(utensils, n);
    int *count;

    copy = memcpy(copy, utensils, n);
    count = malloc(sizeof(int) * (max + 1));
    bzero(count, (sizeof(ing) * (max + 1)))
    for (int i = 0; i < n; i++)
        count[untensils[i]]++;
    for (int i = 1; i < (max + 1); i++)
        count[i] = count[i - 1];
    for (int i = 0; i < n; i++)
    {
        utensils[count[copy[i]] - 1] = copy[i];
        count[copy[i]]--;
    }
}
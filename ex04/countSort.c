/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 22:28:59 by victor            #+#    #+#             */
/*   Updated: 2019/06/14 23:22:20 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int  get_max(unsigned char *utensils, int n){
    int max = 0;
    for (int i = 0; i < n; i++)
        if(utensils[i] > max )
            max = utensils[i];
    return (max);
}

void countSort(unsigned char *utensils, int n){
    unsigned char *copy = malloc(n);
    int max = get_max(utensils, n);
    int *count;

    copy = memcpy(copy, utensils, n);
    count = malloc(sizeof(int) * (max + 1));
    bzero(count, (sizeof(int) * (max + 1)));
    for (int i = 0; i < n; i++)
        count[utensils[i]]++;
    for (int i = 1; i < (max + 1); i++)
        count[i] += count[i - 1];
    for (int i = 0; i < n; i++)
    {
        utensils[count[copy[i]] - 1] = copy[i];
        count[copy[i]]--;
    }
}
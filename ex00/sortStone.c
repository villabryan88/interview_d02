/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:03:23 by bvilla            #+#    #+#             */
/*   Updated: 2019/06/13 15:22:49 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void stone_swap(struct s_stone **a, struct s_stone **b){
	struct s_stone *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sortStones(struct s_stone **stone){
	char swapped = 1;
	struct s_stone **curr = stone;
	struct s_stone **next;

	if (!stone || *stone || (*stone)->next)
		return ;
	while (swapped)
	{
		swapped = 0;
		for (struct s_stone *i; i->next; i = i->next)
		{
			next = &(i->next);
			if((*curr)->size > (*next)->size)
			{
				stone_swap(curr, next);
				swapped = 1;
			}
		}
	}	
}
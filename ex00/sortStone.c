/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:03:23 by bvilla            #+#    #+#             */
/*   Updated: 2019/06/13 15:50:04 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void stone_swap(struct s_stone **curr_adr){
	struct s_stone *curr = *curr_adr;
	struct s_stone *next = curr->next;
	struct s_stone *next_next = next->next;

	*curr_adr = next;
	(*curr_adr)->next = curr;
	(*curr_adr)->next->next = next_next;
}

void sortStones(struct s_stone **stone){
	char swapped = 1;
	struct s_stone **curr;

	if (!stone || !*stone || !(*stone)->next)
		return ;
	while (swapped)
	{
		swapped = 0;
		for (curr = stone; (*curr)->next; curr = &((*curr)->next))
		{
			if((*curr)->size > ((*curr)->next)->size)
			{
				stone_swap(curr);
				swapped = 1;
			}
		}
	}	
}
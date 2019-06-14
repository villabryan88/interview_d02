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

void stone_swap(struct s_stone **curr_adr, struct s_stone **curr_nexp, struct s_stone **next_nexp){
	struct s_stone *curr = *curr_adr;
	struct s_stone *next = *curr_nexp;
	struct s_stone *next_next = *next_nexp;

	*curr_adr = next;
	*next_nexp = curr;
	*curr_nexp = next_next;
} 

void sortStones(struct s_stone **stone){
	int	 n = 0;
	int  last = -1;
	int	 stop;
	int  swapped = 0;
	struct s_stone **next;
	struct s_stone **curr;
	struct s_stone **next_next;

	if (!stone || !*stone || !(*stone)->next)
		return ;
	while (last == -1 || last > 0)
	{

		n = 0;
		stop = last;
		last = 0;
		curr = stone;
		next = &((*curr)->next);
		while (n != stop && *next) 
		{	
			while (*next && (*curr)->size == (*next)->size)
				next = &((*next)->next);
			if(*next)
			{	
				next_next = &((*next)->next);
				if(*next && (*curr)->size > (*next)->size)
				{
					while(*next_next && (*next)->size == (*next_next)->size)
						next_next = &((*next_next)->next);

					stone_swap(curr, next, next_next);
					printf("swap\n");
					swapped = 1;
					last = n;
				}
			}
			if (swapped)
			{
			next = next;
			curr = next_next;
			swapped = 0;
			}
			else
			{
				curr = next;
				next = next_next;
			}

			n++;
		}
	}
}	

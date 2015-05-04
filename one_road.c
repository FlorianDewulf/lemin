/*
** one_road.c for lem_in in /home/seth/Desktop/Lem INNNNN
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Sun Apr 22 21:57:41 2012 kevin lansel
** Last update Sun Apr 22 22:33:31 2012 kevin lansel
*/

#include	"lem_in.h"
#include	<stdlib.h>
#include	<stdio.h>

void		cut_one_road(t_road *mv, t_road *end, int ants, int *i)
{
  while (mv != NULL && end->rway->full <= ants)
    {
      if (mv->rway->full == 0)
	mv = mv->prev;
      else
	{
	  mv->next->rway->full = mv->rway->full;
	  if (mv->next->rway->full <= ants)
	    printf("P%i-%s", mv->next->rway->full, mv->next->rway->name);
	  if (mv->rway->prev != NULL)
	    {
	      if (mv->rway->full < ants)
		printf(" ");
	      mv->rway->full = 0;
	    }
	  else
	    {
	      mv->rway->full = (*i)++;
	      printf("\n");
	    }
	  mv = mv->prev;
	}
    }
}

void		one_road(int ants, t_road *road, int i, t_road *end)
{
  t_road	*mv;

  while (end->rway->full <= ants)
    {
      mv = end_road(road);
      mv->rway->full = 0;
      road->rway->full = i;
      cut_one_road(mv, end, ants, &i);
    }
}

/*
** two_road.c for lem_in in /home/seth/Desktop/Lem INNNNN
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Sun Apr 22 22:14:39 2012 kevin lansel
** Last update Sun Apr 22 22:33:46 2012 kevin lansel
*/

#include	"lem_in.h"
#include	<stdlib.h>
#include	<stdio.h>

static void	cut_two_road_one(t_road *mv1, t_road *end, int ants, int *i)
{
  while (mv1 != NULL && end->rway->full <= ants)
    {
      if (mv1->rway->full == 0)
	mv1 = mv1->prev;
      else
	{
	  mv1->next->rway->full = mv1->rway->full;
	  if (mv1->next->rway->full <= ants)
	    printf("P%i-%s", mv1->next->rway->full, mv1->next->rway->name);
	  if (mv1->rway->prev != NULL)
	    {
	      if (mv1->rway->full < ants)
		printf(" ");
	      mv1->rway->full = 0;
	    }
	  else
	    {
	      mv1->rway->full = (*i)++;
	      printf(" ");
	    }
	  mv1 = mv1->prev;
	}
    }
}

static void	cut_two_road_two(t_road *mv2, t_road *end, int ants, int *i)
{
  while (mv2 != NULL && end->rway->full <= ants)
    {
      if (mv2->rway->full == 0)
	mv2 = mv2->prev;
      else
	{
	  mv2->next->rway->full = mv2->rway->full;
	  if (mv2->next->rway->full <= ants)
	    printf("P%i-%s", mv2->next->rway->full, mv2->next->rway->name);
	  if (mv2->rway->prev != NULL)
	    {
	      if (mv2->rway->full < ants)
		printf(" ");
	      mv2->rway->full = 0;
	    }
	  else
	    {
	      mv2->rway->full = (*i)++;
	      printf("\n");
	    }
	  mv2 = mv2->prev;
	}
    }
}

void		two_road(int ants, t_road *road1, t_road *road2, int i)
{
  t_road	*mv1;
  t_road	*mv2;
  t_road	*end;

  mv1 = end_road(road1);
  mv2 = end_road(road2);
  end = end_road(road1);
  while (end->rway->full <= ants)
    {
      mv1 = end_road(road1);
      mv1->rway->full = 0;
      road1->rway->full = i;
      cut_two_road_one(mv1, end, ants, &i);
      mv2 = end_road(road2);
      mv2->rway->full = 0;
      road2->rway->full = i;
      cut_two_road_two(mv2, end, ants, &i);
    }
  printf("\n");
}

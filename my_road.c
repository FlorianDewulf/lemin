/*
** my_road.c for lem_in in /home/seth/Desktop/Lem INNNNN
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Sun Apr 22 18:25:04 2012 kevin lansel
** Last update Sun Apr 22 18:40:03 2012 kevin lansel
*/

#include	"lem_in.h"
#include	<stdlib.h>

void		my_road2(t_road *road2, int time, t_link *tmp2)
{
  t_lem		*ptr;

  while (time >= 0 && tmp2 != NULL)
    {
      ptr = link_road2(tmp2, &time);
      if (ptr != NULL)
	{
	  tmp2->way->view = 0;
	  tmp2 = ptr->link;
	  list_road_init(road2, ptr);
	}
      else
	tmp2 = NULL;
    }
}

void		my_road1(t_road *road1, int time, t_link *tmp1)
{
  t_lem		*ptr;

  while (time >= 0 && tmp1 != NULL)
    {
      ptr = link_road1(tmp1, &time);
      if (ptr != NULL)
	{
	  tmp1->way->view = 0;
	  tmp1 = ptr->link;
	  list_road_init(road1, ptr);
	  if (ptr->time == 0)
	    ptr->view = 1;
	}
      else
	tmp1 = NULL;
    }
}

/*
** check_road.c for lem_in in /home/seth/Desktop/Lem INNNNN
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Sun Apr 22 18:55:26 2012 kevin lansel
** Last update Sun Apr 22 22:35:13 2012 kevin lansel
*/

#include	"lem_in.h"
#include	<stdlib.h>

t_road		*check_road1(t_road *road1)
{
  t_road	*tmp;

  if (road1 != NULL)
    {
      tmp = road1;
      while (tmp->next != NULL)
	tmp = tmp->next;
      if (tmp->rway->time == 0)
	return (road1);
      else
	return (NULL);
    }
  else
    return (NULL);
}

t_road		*check_road2(t_road *road2)
{
  t_road	*tmp;

  if (road2 != NULL)
    {
      tmp = road2;
      while (tmp->next != NULL)
	tmp = tmp->next;
      if (tmp->rway->time == 0)
	return (road2);
      else
	return (NULL);
    }
  else
    return (NULL);
}

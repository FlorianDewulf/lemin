/*
** link_road.c for lem_in.h in /home/seth/Desktop/Lem INNNNN
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Sun Apr 22 18:51:51 2012 kevin lansel
** Last update Sun Apr 22 18:52:26 2012 kevin lansel
*/

#include	"lem_in.h"
#include	<stdlib.h>

t_lem		*link_road1(t_link *tmp, int *time)
{
  t_lem		*ptr;

  ptr = NULL;
  while (tmp != NULL)
    {
      if (tmp->way->view == 1 && (*time) > tmp->way->time)
	{
	  tmp->way->view = 0;
	  (*time) = tmp->way->time;
	  ptr = tmp->way;
	}
      tmp = tmp->next;
    }
  if (ptr == NULL)
    (*time) = 0;
  return (ptr);
}

t_lem		*link_road2(t_link *tmp, int *time)
{
  t_lem		*ptr;

  ptr = NULL;
  while (tmp != NULL)
    {
      if (tmp->way->view == 1 && (*time) != 0)
	{
	  tmp->way->view = 0;
	  (*time) = tmp->way->time;
	  ptr = tmp->way;
	}
      tmp = tmp->next;
    }
  if (ptr == NULL)
    (*time) = 0;
  return (ptr);
}

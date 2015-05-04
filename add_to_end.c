/*
** add_to_end.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Thu Apr  5 08:34:55 2012 kevin lansel
** Last update Sun Apr 22 18:46:02 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lem_in.h"

void		add_to_end_graph(t_lem **lem, t_lem *elem)
{
  t_lem		*ptr;

  ptr = *lem;
  if (*lem == NULL)
    *lem = elem;
  else
    {
      while (ptr->next != NULL)
	ptr = ptr->next;
      elem->prev = ptr;
      ptr->next = elem;
    }
}

void		add_to_end_link(t_lem *lem, t_link *elem)
{
  t_link	*ptr;

  ptr = lem->link;
  if (lem->link == NULL)
    lem->link = elem;
  else
    {
      while (ptr->next != NULL)
	ptr = ptr->next;
      elem->prev = ptr;
      ptr->next = elem;
    }
}

t_road		*add_to_end_road(t_road *road, t_road *elem)
{
  t_road	*ptr;

  ptr = road;
  if (road == NULL)
    road = elem;
  else
    {
      while (ptr->next != NULL)
	ptr = ptr->next;
      elem->prev = ptr;
      ptr->next = elem;
    }
  return (road);
}

/*
** way.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Tue Apr 17 08:23:54 2012 kevin lansel
** Last update Sun Apr 22 22:15:13 2012 kevin lansel
*/

#include	"lem_in.h"
#include	<stdlib.h>

void		way(int time, t_lem *room)
{
  t_link	*tmp;

  if (room->view == 0 || time < room->time)
    {
      room->view = 1;
      room->time = time;
      tmp = room->link;
      while (tmp != NULL)
	{
	  way(time + 1, tmp->way);
	  tmp = tmp->next;
	}
    }
}

void		road(t_lem *room, int ants)
{
  t_road	*road1;
  t_road	*road2;
  t_link	*tmp1;
  t_link	*tmp2;
  int		time;

  room->view = 0;
  road1 = NULL;
  road2 = NULL;
  road1 = list_road_init(road1, room);
  tmp1 = room->link;
  time = room->time;
  my_road1(road1, time, tmp1);
  if (room->link->next != NULL)
    {
      road2 = list_road_init(road2, room);
      tmp2 = room->link;
      time = room->time;
      my_road2(road2, time, tmp2);
    }
  road1 = check_road1(road1);
  road2 = check_road2(road2);
  move_ants(ants, road1, road2);
}

void		move_ants(int ants, t_road *road1, t_road *road2)
{
  t_road	*end;

  if (road1 != NULL && road2 == NULL)
    {
      end = end_road(road1);
      one_road(ants, road1, 1, end);
    }
  else if (road1 == NULL && road2 != NULL)
    {
      end = end_road(road1);
      one_road(ants, road2, 1, end);
    }
 else if (road1 != NULL && road2 != NULL)
    two_road(ants, road1, road2, 1);
  else
    my_puterror("No road to end\n");
}

t_road		*end_road(t_road *road)
{
  t_road	*end;

  end = road;
  while (end->next != NULL)
    end = end->next;
  return (end);
}

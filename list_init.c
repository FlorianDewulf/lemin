/*
** list_init.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Thu Apr  5 08:29:15 2012 kevin lansel
** Last update Sun Apr 22 18:46:01 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lem_in.h"

void		list_graph_init(t_lem **lem, char *line)
{
  char		**tab;
  t_lem		*elem;

  tab = my_str_to_wordtab(line, ' ');
  elem = xmalloc(sizeof(t_lem));
  elem->name = xmalloc(sizeof(char) * (my_strlen(tab[0]) + 1));
  my_strcpy(elem->name, tab[0]);
  elem->x = my_getnbr(tab[1]);
  elem->y = my_getnbr(tab[2]);
  elem->time = -1;
  elem->view = 0;
  elem->view = 0;
  elem->next = NULL;
  elem->prev = NULL;
  elem->link = NULL;
  add_to_end_graph(lem, elem);
}

void		list_link_init(t_lem *lem, t_lem *ptr)
{
  t_link	*elem;

  elem = xmalloc(sizeof(t_link));
  elem->way = ptr;
  elem->next = NULL;
  elem->prev = NULL;
  add_to_end_link(lem, elem);
}

t_road		*list_road_init(t_road *road, t_lem *ptr)
{
  t_road	*elem;

  elem = xmalloc(sizeof(t_road));
  elem->rway = ptr;
  elem->next = NULL;
  elem->prev = NULL;
  road = add_to_end_road(road, elem);
  return (road);
}

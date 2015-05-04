/*
** main.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Mon Apr  2 13:26:54 2012 kevin lansel
** Last update Sun Apr 22 22:12:44 2012 kevin lansel
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lem_in.h"
#include	"lemin.h"

t_lem		*my_nod(char *name, t_lem **lem)
{
  t_lem		*ptr;

  ptr = *lem;
  while (ptr != NULL)
    {
      if (my_strcmp(name, ptr->name) == 0)
	return (ptr);
      ptr = ptr->next;
    }
  return (NULL);
}

t_lem		*end_graph(t_lem **lem)
{
  t_lem		*end;

  end = *lem;
  while (end->next != NULL)
    end = end->next;
  return (end);
}

void		add_to_graph(t_conf **conf, t_lem **lem, int ants)
{
  t_conf	*ptr;
  char		**tab;
  t_lem		*nod1;
  t_lem		*nod2;

  ptr = *conf;
  while (ptr != NULL)
    {
      if (my_match(ptr->line, '-') == 1)
	{
	  tab = my_str_to_wordtab(ptr->line, '-');
	  nod1 = my_nod(tab[0], lem);
	  nod2 = my_nod(tab[1], lem);
	  link_room(lem, nod1, nod2);
	}
      ptr = ptr->next;
    }
  way(0, end_graph(lem));
  road(*lem, ants);
}

void		my_graph(t_conf **conf, int four)
{
  t_conf	*ptr;
  t_lem		*lem;

  lem = NULL;
  ptr = *conf;
  while (ptr != NULL)
    {
      if (my_match(ptr->line, ' ') == 1 && my_match(ptr->line, '-') == 0)
	list_graph_init(&lem, ptr->line);
      ptr = ptr->next;
    }
  add_to_graph(conf, &lem, four);
}

void		game(t_conf *conf)
{
  int		four;

  four = my_getnbr(conf->line);
  my_graph(&conf, four);
}

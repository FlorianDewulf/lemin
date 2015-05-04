/*
** main.c for  in /home/lund/Dossier courant/lem_in
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sat Apr  7 13:24:07 2012 florian dewulf
** Last update Sun Apr 22 18:47:23 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lemin.h"
#include	"lem_in.h"

static void	put_to_list(char *line, t_conf **list)
{
  t_conf	*elem;
  t_conf	*tmp;

  elem = xmalloc(sizeof(t_conf));
  elem->line = line;
  elem->next = NULL;
  if (*list == NULL)
    {
      elem->previous = NULL;
      *list = elem;
    }
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      elem->previous = tmp;
      tmp->next = elem;
    }
}

static void	modification_pipe(t_conf **list)
{
  t_conf	*tmp;

  tmp = *list;
  while (tmp && !check_pipe(tmp->line))
    tmp = tmp->next;
  while (tmp != NULL)
    {
      tmp->line = modif_pipe(tmp->line);
      tmp = tmp->next;
    }
}

int		main()
{
  t_conf	*list;
  char		*str;

  list = NULL;
  while ((str = get_next_line(0)))
    {
      my_putstr(str);
      my_putchar('\n');
      if (str[0] != '\0' && space_check(str))
	put_to_list(str, &list);
    }
  check_pre_list(&list);
  epur_and_sort(&list);
  check_list(&list);
  modification_pipe(&list);
  suppr_double(&list);
  game(list);
  return (0);
}

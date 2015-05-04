/*
** suppr.c for lemin in /home/lund/Dossier courant/lem_in/test
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu Apr 19 13:27:29 2012 florian dewulf
** Last update Thu Apr 19 17:18:52 2012 florian dewulf
*/

#include	<stdlib.h>
#include	"lemin.h"

static void	rm_maille(t_conf **list, t_conf **to_rm)
{
  t_conf	*tmp1;
  t_conf	*tmp2;

  if ((*to_rm) == (*list))
    {
      (*list) = (*list)->next;
      (*list)->previous = NULL;
      free((*to_rm)->line);
      free(*to_rm);
      (*to_rm) = *list;
    }
  else
    {
      tmp1 = (*to_rm)->previous;
      tmp2 = (*to_rm)->next;
      if (tmp1 != NULL)
	tmp1->next = tmp2;
      if (tmp2 != NULL)
	tmp2->previous = tmp1;
      free((*to_rm)->line);
      free((*to_rm));
      *to_rm = tmp2;
    }
}

void		suppr_double(t_conf **list)
{
  t_conf	*tmp;
  t_conf	*tempo;

  tmp = *list;
  while (tmp != NULL)
    {
      tempo = *list;
      while (tempo != NULL)
	{
	  if (tempo != tmp && comp(tmp->line, tempo->line))
	    rm_maille(list, &tempo);
	  else
	    tempo = tempo->next;
	}
      tmp = tmp->next;
    }
}

int		space_check(char *str)
{
  int		curs;

  curs = -1;
  while (str[++curs] == ' ' || str[curs] == '\t');
  if (str[curs] == '\0')
    return (0);
  else
    return (1);
}

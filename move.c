/*
** move.c for lemin in /home/lund/Dossier courant/lem_in
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Fri Apr  6 13:36:26 2012 florian dewulf
** Last update Sat Apr 21 17:41:22 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lemin.h"

static void	move_begin(t_conf **list, t_conf *tmp,
			   t_conf *previous_tmp, t_conf *next_tmp)
{
  previous_tmp->next = next_tmp;
  if (next_tmp != NULL)
    next_tmp->previous = previous_tmp;
  tmp->previous = (*list);
  tmp->next = (*list)->next;
  ((*list)->next)->previous = tmp;
  (*list)->next = tmp;
}

static void	move_end(t_conf *tmp,
			 t_conf *previous_tmp, t_conf *next_tmp)
{
  t_conf	*end;

  end = tmp;
  while (!check_pipe(end->line) && end->next != NULL)
    end = end->next;
  if (end == tmp)
    return;
  previous_tmp->next = next_tmp;
  next_tmp->previous = previous_tmp;
  tmp->previous = end->previous;
  end->previous->next = tmp;
  tmp->next = end;
  end->previous = tmp;
}

void		remove_com(t_conf **list, t_conf **tmp)
{
  t_conf	*tmp1;
  t_conf	*tmp2;

  if ((*list) == *tmp)
    {
      (*list) = (*list)->next;
      free((*tmp)->line);
      free(*tmp);
      *tmp = *list;
    }
  else
    {
      tmp2 = (*tmp)->next;
      tmp1 = (*tmp)->previous;
      free((*tmp)->line);
      free(*tmp);
      tmp1->next = tmp2;
      if (tmp2 == NULL)
	*tmp = NULL;
      else
	{
	  tmp2->previous = tmp1;
	  *tmp = tmp2;
	}
    }
}

void		move_maille(t_conf **list, int ret, char *str)
{
  t_conf	*tmp;
  t_conf	*previous_tmp;
  t_conf	*next_tmp;

  tmp = *list;
  if (ret == 1 && tmp->next && comp(tmp->next->line, str))
    return;
  while (tmp != NULL && !comp(tmp->line, str))
    tmp = tmp->next;
  if (tmp == NULL)
    my_puterror("Fail improbable\n");
  tmp->where = ret;
  previous_tmp = tmp->previous;
  next_tmp = tmp->next;
  if (ret == 1)
    move_begin(list, tmp, previous_tmp, next_tmp);
  else
    move_end(tmp, previous_tmp, next_tmp);
}

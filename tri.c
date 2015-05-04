/*
** tri.c for lemin in /home/lund/Dossier courant/lem_in
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Apr  4 14:06:14 2012 florian dewulf
** Last update Thu Apr 19 18:17:07 2012 florian dewulf
*/

#include	<stdlib.h>
#include	"lemin.h"

static int	check_first_line(char *str)
{
  int	curs;

  curs = -1;
  while (str[++curs] == ' ' || str[curs] == '\t');
  while (str[curs] && str[curs] != ' ' && str[curs] != '\t')
    {
      if (curs == 0 && str[curs] == '+')
	while (str[curs] == '+')
	  curs++;
      else if (str[curs] >= '0' && str[curs] <= '9')
	curs++;
      else
	return (1);
    }
  while (str[curs] == ' ' || str[curs] == '\t')
    curs++;
  if (str[curs] != '\0')
    return (1);
  return (0);
}

static void	sort_list(t_conf **list)
{
  t_conf	*tmp;
  int		ret;
  t_conf	*tempo;

  tmp = (ret = 0) ? (*list) : (*list);
  while (tmp != NULL)
    {
      if ((ret = check_instruction(tmp->line)) != 0)
	{
	  tmp->previous->next = tmp->next;
	  tmp->next->previous = tmp->previous;
	  tempo = tmp->next;
	  free(tmp->line);
	  free(tmp);
	  tmp = tempo->next;
	  move_maille(list, ret, tempo->line);
	}
      else if (check_com(tmp->line))
	remove_com(list, &tmp);
      else
	tmp = tmp->next;
    }
}

static void	check_pre_sort(t_conf **list, int repere, int size)
{
  if (repere == 0)
    my_puterror(ERROR_INSTRU);
  if (repere == 1)
    my_puterror(MISS_END);
  if (repere == 2)
    my_puterror(MISS_START);
  if (repere != 3)
    my_puterror(TOO_MANY_INSTR);
  if (size < 6)
    my_puterror(NOVALID);
  sort_list(list);
  check_link(list);
}

static void	check_the_line(int *pipe_ind, t_conf **tmp,
			       int pos_tab, int *repere)
{
  if (check_instruction((*tmp)->line))
    {
      (*repere) += check_instruction((*tmp)->line);
      if (!((*tmp)->next) || !check_room((*tmp)->next->line, *pipe_ind))
	my_puterror(FOLLOW_INSTRU);
    }
  else if (!(check_com((*tmp)->line) ||
	     (*pipe_ind += check_pipe((*tmp)->line)) ||
	     check_room((*tmp)->line, *pipe_ind)))
    put_error_line(pos_tab + 1);
}

void	check_list(t_conf **list)
{
  t_conf	*tmp;
  int		pos_tab;
  int		repere;
  int		pipe_ind;

  pipe_ind = 0;
  repere = 0;
  pos_tab = -1;
  tmp = *list;
  while (tmp)
    {
      if (++pos_tab == 0)
	if (check_first_line(tmp->line))
	  my_puterror(BENUMBER);
      if (pos_tab != 0)
	check_the_line(&pipe_ind, &tmp, pos_tab, &repere);
      tmp = tmp->next;
    }
  check_pre_sort(list, repere, pos_tab + 1);
}

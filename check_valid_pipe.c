/*
** check_valid_pipe.c for  in /home/lund/Dossier courant/lem_in
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu Apr 12 14:14:45 2012 florian dewulf
** Last update Sun Apr 22 23:19:12 2012 florian dewulf
*/

#include	<stdlib.h>
#include	"lemin.h"

static int	check_tab_link(char *str, t_conf *tmp)
{
  int		repere;
  t_conf	*tempo;
  int		total;

  total = 0;
  tempo = tmp;
  while (tempo != NULL)
    {
      repere = -1;
      while (tempo->line[++repere] && tempo->line[repere] != '-');
      if (comp_to_char(str, repere, tempo->line))
	total++;
      if (comp_from_char(tempo->line, repere + 1, str))
	total++;
      tempo = tempo->next;
    }
  return (total);
}

static int	check_valid_link(t_conf **list, char **pattern)
{
  int		curs;
  t_conf	*tempo;

  curs = -1;
  tempo = *list;
  while (pattern[++curs + 1]);
  while (tempo && !check_pipe(tempo->line))
    tempo = tempo->next;
  if (check_tab_link(pattern[0], tempo) == 0)
    return (-2);
  if (check_tab_link(pattern[curs], tempo) == 0)
    return (-2);
  free_tab(pattern);
  return (0);
}

static int	reduc_valid(char **pattern, char *str, int curs)
{
  int		pos;

  pos = 0;
  while (pos != -1 && pattern[pos])
    if (comp_to_char(pattern[pos++], curs, str))
      pos = -1;
  if (pos != -1)
    return (-1);
  return (0);
}

int		check_valid_pipe(char **pattern, t_conf **list)
{
  t_conf	*tmp;
  int		curs;
  int		pos;

  tmp = *list;
  while (tmp && !check_pipe(tmp->line))
    tmp = tmp->next;
  while (tmp)
    {
      curs = -1;
      while (tmp->line[++curs] != '-' && tmp->line[curs]);
      pos = reduc_valid(pattern, tmp->line, curs);
      if (pos == -1)
	return (-1);
      pos = 0;
      while (pos != -1 && pattern[pos])
	if (comp_from_char(tmp->line, curs + 1, pattern[pos++]))
	  pos = -1;
      if (pos != -1)
	return (-1);
      tmp = tmp->next;
    }
  return (check_valid_link(list, pattern));
}

int		check_post_pipe(char *str)
{
  int		cur;
  int		tmp;

  cur = -1;
  while (str[++cur] == ' ' || str[cur] == '\t');
  tmp = cur;
  while ((str[cur] != '-' || (str[cur] != ' ' && str[cur] != '\t')) && str[cur])
    cur++;
  if (str[cur] == ' ' || str[cur] == '\t')
    while (str[cur] != '-' && str[cur])
      cur++;
  if (!str[cur])
    my_puterror(ERROR_FILE);
  while (str[++cur] && (str[cur] == ' ' || str[cur] == '\t'));
  if (!str[cur])
    my_puterror(ERROR_FILE);
  while (str[cur] && str[cur] != ' ' && str[cur] != '\t')
    cur++;
  while (str[cur] == ' ' || str[cur] == '\t')
    cur++;
  if (!str[cur])
    return (1);
  return (0);
}

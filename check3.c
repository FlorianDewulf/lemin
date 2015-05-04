/*
** check3.c for lemin in /home/lund/Dossier courant/lem_in/test
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Apr 18 13:18:12 2012 florian dewulf
** Last update Sat Apr 21 17:38:34 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lemin.h"

int		check_pres_link(char *str)
{
  int		curs;
  int		link;

  link = 0;
  curs = -1;
  while (str[++curs])
    if (str[curs] == '-')
      link++;
  if (link == 1 && str[0] != '#')
    return (1);
  if (link > 1 && str[0] != '#')
    return (2);
  return (0);
}

int		check_alink(char *str)
{
  int		curs;
  int		tmp;

  curs = -1;
  if (check_pres_link(str) != 1)
    return (0);
  while (str[++curs] == ' ' || str[curs] == '\t');
  tmp = curs;
  while (str[curs] != '-' && str[curs] != ' ' && str[curs])
    curs++;
  while (str[curs] == ' ' || str[curs] == '\t')
    curs++;
  if (tmp == curs || str[curs] != '-')
    return (0);
  curs++;
  while (str[curs] == ' ' || str[curs] == '\t')
    curs++;
  tmp = curs;
  while (str[curs] && str[curs] != ' ' && str[curs] != '\t')
    curs++;
  while (str[curs] == ' ' || str[curs] == '\t')
    curs++;
  if (tmp == curs || str[curs] != '\0')
    return (0);
  return (1);
}

void		check_pre_list(t_conf **list)
{
  t_conf	*tmp;
  int		indic;
  int		line;

  line = 1;
  indic = 0;
  tmp = *list;
  while (tmp)
    {
      if (check_pres_link(tmp->line) == 2)
	put_error_line(line);
      if (check_pres_link(tmp->line) == 0 && indic == 1)
	put_error_line(line);
      if (check_pres_link(tmp->line) == 1)
	indic++;
      tmp = tmp->next;
    }
  if (indic == 0)
    my_puterror(NOLINK);
}

void		navig_to_link(t_conf **list)
{
  while ((*list) && check_pres_link((*list)->line) != 1)
    (*list) = (*list)->next;
  if ((*list) == NULL)
    my_puterror(NOLINK);
}

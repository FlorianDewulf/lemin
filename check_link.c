/*
** check_link.c for  in /home/lund/Dossier courant/lem_in
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu Apr 12 10:17:47 2012 florian dewulf
** Last update Sat Apr 21 17:39:48 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lemin.h"

static char	*copy_str(int size, int begin, char *str)
{
  char		*dest;
  int		curs;

  curs = 0;
  dest = xmalloc(size * sizeof(char));
  while (str[begin] != ' ' && str[begin] != '\t' && str[begin])
    dest[curs++] = str[begin++];
  dest[curs] = '\0';
  return (dest);
}

static char	**put_room_to_tab(t_conf **list, int curs)
{
  char		**pattern;
  int		pos;
  t_conf	*tmp;
  int		index;
  int		tempo;

  pos = 0;
  tempo = 0;
  tmp = (*list)->next;
  pattern = xmalloc(curs * sizeof(char *));
  while (tmp && !check_pipe(tmp->line))
    {
      index = -1;
      while (tmp->line[++index] == ' ' || tmp->line[index] == '\t');
      tempo = index;
      while (tmp->line[index] && tmp->line[index] != ' ' &&
	     tmp->line[index] != '\t')
	index++;
      pattern[pos++] = copy_str(index - tempo + 1, tempo, tmp->line);
      tmp = tmp->next;
    }
  pattern[pos] = NULL;
  return (pattern);
}

void		check_link(t_conf **list)
{
  int		curs;
  t_conf	*tmp;
  char		**pattern;

  curs = 0;
  tmp = *list;
  while (tmp && !check_pipe(tmp->line))
    {
      curs++;
      tmp = tmp->next;
    }
  pattern = put_room_to_tab(list, curs);
  if ((curs = check_valid_pipe(pattern, list)) < 0)
    {
      if (curs == -1)
	my_puterror(NOROOM);
      else if (curs == -2)
	my_puterror(NOLINK_INSTRU);
    }
}

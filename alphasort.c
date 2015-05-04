/*
** alphasort.c for lemin in /home/lund/svn/lemin-2016-dewulf_f
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Apr 16 18:16:40 2012 florian dewulf
** Last update Sat Apr 21 17:27:57 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lemin.h"

static int	inversion(char *str)
{
  char		*tmp;
  int		curs;
  int		curs2;

  curs2 = 0;
  curs = -1;
  tmp = xmalloc((my_strlen(str) + 1) * sizeof(char));
  while (str[++curs])
    tmp[curs] = str[curs];
  tmp[curs] = '\0';
  while (tmp[--curs] != '-' && curs > 0);
  while (tmp[++curs])
    str[curs2++] = tmp[curs];
  str[curs2++] = '-';
  curs = 0;
  while (tmp[curs] && tmp[curs] != '-')
    str[curs2++] = tmp[curs++];
  str[curs2] = '\0';
  free(tmp);
  return (0);
}

static char	*alphasort(char *str)
{
  int		curs;
  int		curs_two;
  int		indice;

  indice = 1;
  curs = 0;
  curs_two = -1;
  while (str[++curs_two] && str[curs_two] != '-');
  curs_two++;
  while (indice && str[curs] != '-' && str[curs_two] != '\0')
    {
      if (str[curs] <= str[curs_two])
	{
	  curs++;
	  curs_two++;
	}
      else
	indice = inversion(str);
    }
  return (str);
}

static char	*epur_line(char *str)
{
  char		*dest;
  int		curs;
  int		pos;

  pos = 0;
  curs = -1;
  dest = xmalloc((my_strlen(str) + 1) * sizeof(char));
  while (str[++curs])
    if (str[curs] != ' ' && str[curs] != '\t')
      dest[pos++] = str[curs];
  dest[pos] = '\0';
  if (pos < 2)
    my_puterror(STRANGE);
  free(str);
  return (dest);
}

static char	*epur_room(char *str)
{
  char		*dest;
  int		curs;
  int		pos;

  curs = 0;
  pos = 0;
  dest = xmalloc((my_strlen(str) + 1) * sizeof(char));
  while (str[curs])
    {
      while (str[curs] == ' ' || str[curs] == '\t')
	curs++;
      while (str[curs] && str[curs] != ' ' && str[curs] != '\t')
	dest[pos++] = str[curs++];
      while (str[curs] == ' ' || str[curs] == '\t')
	curs++;
      if (str[curs])
	dest[pos++] = ' ';
    }
  dest[pos] = '\0';
  return (dest);
}

void		epur_and_sort(t_conf **list)
{
  t_conf	*tmp;
  t_conf	*tempo;
  int		curs;

  tempo = (tmp = *list) ? *list : *list;
  curs = 0;
  navig_to_link(&tempo);
  if (tmp == tempo || !check_valid_chars(tmp->line, "0123456789"))
    my_puterror(USAGE);
  tmp = tmp->next;
  while (tmp != tempo)
    {
      if (!(check_com(tmp->line) || check_instruction(tmp->line)))
	curs += (tmp->line = epur_room(tmp->line)) ? 1 : 1;
      tmp = tmp->next;
    }
  if (curs == 0)
    my_puterror(USAGE);
  while (tempo != NULL)
    {
      tempo->line = epur_line(tempo->line);
      tempo->line = alphasort(tempo->line);
      tempo = tempo->next;
    }
}

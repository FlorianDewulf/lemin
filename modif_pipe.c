/*
** modif_pipe.c for  in /home/lund/svn/lemin-2016-dewulf_f
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Fri Apr 13 13:34:49 2012 florian dewulf
** Last update Thu Apr 19 16:37:52 2012 florian dewulf
*/

#include	<stdlib.h>
#include	"lemin.h"

static char	*pastie(char *str)
{
  char		**tab;
  char		*ret;
  char		*tmp;
  char		*tempo;
  int		curs;

  curs = -1;
  tab = str_to_wordtab(str);
  while (tab[++curs]);
  if (curs == 3)
    tmp = tab[2];
  ret = concate(tab[0], tab[1]);
  free(tab[0]);
  free(tab[1]);
  free(tab);
  if (curs == 3)
    {
      tempo = ret;
      ret = concate(tempo, tmp);
      free(tempo);
      free(tmp);
    }
  return (ret);
}

char		*modif_pipe(char *str)
{
  int		curs;
  int		indice;

  curs = -1;
  indice = 0;
  while (str[++curs])
    if (str[curs] == ' ' || str[curs] == '\t')
      indice++;
  if (indice == 0)
    return (str);
  else
    return (pastie(str));
}

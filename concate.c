/*
** concate.c for  in /home/lund/Dossier courant/lem_in
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sat Apr  7 13:40:09 2012 florian dewulf
** Last update Mon Apr  9 19:26:09 2012 florian dewulf
*/

#include	"lemin.h"

char	*concate(char *partone, char *parttwo)
{
  char	*ret;
  int	curs;
  int	i;

  i = 0;
  curs = 0;
  ret = xmalloc((my_strlen(partone) + my_strlen(parttwo) + 1) * sizeof(char));
  while (partone[i])
    ret[curs++] = partone[i++];
  i = -1;
  while (parttwo[++i])
    ret[curs++] = parttwo[i];
  ret[curs] = '\0';
  return (ret);
}

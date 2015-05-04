/*
** my_strcmp.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Wed Apr  4 14:18:36 2012 kevin lansel
** Last update Thu Apr 12 11:06:35 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lem_in.h"

int		my_strcmp(char *arg, char *comp)
{
  int		i;

  i = 0;
  if (arg == NULL)
    my_puterror(START);
  while (arg[i] != '\0' && comp[i] != '\0')
    {
      if (arg[i] == comp[i])
        i++;
      else
        return (1);
    }
  if (arg[i] == '\0' && comp[i] == '\0')
    return (0);
  else
    return (1);
}

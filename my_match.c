/*
** my_match.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Thu Apr  5 15:55:26 2012 kevin lansel
** Last update Thu Apr  5 16:24:01 2012 kevin lansel
*/

#include	"lem_in.h"

int	my_match(char *str, char m)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  while (str[i])
    {
      if (str[i] == m)
	return (1);
      i++;
    }
  return (0);
}

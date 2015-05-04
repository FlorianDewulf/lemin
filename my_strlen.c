/*
** my_strlen.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Mon Apr  2 14:59:47 2012 kevin lansel
** Last update Mon Apr  2 15:16:07 2012 kevin lansel
*/

#include	"lem_in.h"

int		my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

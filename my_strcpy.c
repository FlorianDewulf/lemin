/*
** my_strcpy.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Thu Apr  5 11:09:36 2012 kevin lansel
** Last update Thu Apr  5 11:15:58 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lem_in.h"

void		my_strcpy(char *dest, char *src)
{
  int		i;

  i = -1;
  while (src[++i] != '\0')
    dest[i] = src[i];
  dest[i] = '\0';
}

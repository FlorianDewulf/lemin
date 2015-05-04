/*
** my_putstr.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Mon Apr  2 14:52:33 2012 kevin lansel
** Last update Mon Apr  2 15:15:23 2012 kevin lansel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lem_in.h"

void		my_putstr(char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    exit(EXIT_FAILURE);
}

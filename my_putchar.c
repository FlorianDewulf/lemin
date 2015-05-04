/*
** my_putchar.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Mon Apr  2 14:51:30 2012 kevin lansel
** Last update Mon Apr  2 15:15:14 2012 kevin lansel
*/

#include	<unistd.h>
#include	<stdlib.h>

void		my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(EXIT_FAILURE);
}

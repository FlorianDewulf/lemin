/*
** error.c for lemin in /home/lund/Dossier courant/lem_in
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu Apr  5 14:28:42 2012 florian dewulf
** Last update Sat Apr 21 17:40:06 2012 kevin lansel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lemin.h"

void		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  exit(EXIT_FAILURE);
}

static void	my_put_nbr_error(int nb)
{
  int	diviseur;
  char	res;

  diviseur = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  while ((nb / diviseur) >= 10)
    {
      diviseur = diviseur * 10;
    }
  while (diviseur > 0)
    {
      res = ((nb / diviseur) % 10 + '0');
      write(2, &res, 1);
      diviseur = diviseur / 10;
    }
}

void		put_error_line(int line)
{
  write(2, ERROR_SYNTAX, 13);
  my_put_nbr_error(line);
  write(2, "\n", 1);
  exit(EXIT_FAILURE);
}

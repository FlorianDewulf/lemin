/*
** my_getnbr.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Wed Apr  4 14:16:11 2012 kevin lansel
** Last update Sat Apr 14 13:27:10 2012 kevin lansel
*/

#include	"lem_in.h"

int		my_getnbr(char *str)
{
  int		p;
  int		s;
  int		nb;

  s = 1;
  p = 0;
  while (str[p] != '\0' && (str[p] == '+' || str[p] =='-'))
    {
      if (str[p] == '-')
        {
          s = s * - 1;
        }
      p = p + 1;
    }
  str = str + p;
  nb = 0;
  p = 0;
  while (str[p] >= '0' && str[p] <= '9')
    {
      nb = nb *10;
      nb = nb - (str[p] - '0');
      p = p + 1;
    }
  return (nb * s * -1);
}

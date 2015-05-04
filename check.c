/*
** check.c for lemin in /home/lund/Dossier courant/lem_in
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Apr  4 17:14:35 2012 florian dewulf
** Last update Sat Apr 21 17:30:57 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lemin.h"

int		check_com(char *str)
{
  int		curs;

  curs = -1;
  while (str[++curs] == ' ' || str[curs] == '\t');
  if (str[curs] == '#')
    {
      if (str[curs + 1] == '#')
	if (comp_from_char(str, curs + 2, "start") ||
	    comp_from_char(str, curs + 2, "end"))
	  return (0);
      return (1);
    }
  return (0);
}

int		check_pipe(char *str)
{
  return (check_alink(str));
}

int		check_instruction(char *str)
{
  if (str[0] == '#')
    {
      if (comp_from_char(str, 1, "#start"))
	return (1);
      else if (comp_from_char(str, 1, "#end"))
	return (2);
    }
  return (0);
}

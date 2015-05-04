/*
** free_tab.c for  in /home/lund/Dossier courant/lem_in
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Apr 11 10:15:14 2012 florian dewulf
** Last update Fri Apr 13 11:54:49 2012 florian dewulf
*/

#include	<stdlib.h>
#include	"lemin.h"

int	free_tab(char **tab)
{
  int	curs;

  curs = -1;
  while (tab[++curs])
    free(tab[curs]);
  free(tab);
  return (1);
}

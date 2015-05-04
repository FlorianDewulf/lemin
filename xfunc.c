/*
** xfunc.c for  in /home/lund/Dossier courant/lem_in
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Apr  9 19:18:59 2012 florian dewulf
** Last update Thu Apr 19 12:27:46 2012 florian dewulf
*/

#include	<stdlib.h>
#include	"lemin.h"

void	*xmalloc(int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    my_puterror(FAIL_MALLOC);;
  return (ptr);
}

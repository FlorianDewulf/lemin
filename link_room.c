/*
** link_nod.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Tue Apr 10 12:27:07 2012 kevin lansel
** Last update Mon Apr 16 20:33:54 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lem_in.h"

void		link_room(t_lem **lem, t_lem *nod1, t_lem *nod2)
{
  t_lem		*ptr;

  ptr = *lem;
  if (nod1 == NULL || nod2 == NULL)
    my_puterror("Erreur linker\n");
  while (ptr != NULL && my_strcmp(ptr->name, nod1->name) == 1)
    ptr = ptr->next;
  if (ptr == NULL)
    my_puterror("Erreur linker\n");
  else if (my_strcmp(ptr->name, nod1->name) == 0)
    list_link_init(ptr, nod2);
  ptr = *lem;
  while (ptr != NULL && my_strcmp(ptr->name, nod2->name) == 1)
    ptr = ptr->next;
  if (ptr == NULL)
    my_puterror("Erreur linker\n");
  else if (my_strcmp(ptr->name, nod2->name) == 0)
    list_link_init(ptr, nod1);
}

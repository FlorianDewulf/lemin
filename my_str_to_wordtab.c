/*
** my_str_to_wordtab.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Wed Apr  4 13:24:51 2012 kevin lansel
** Last update Sat Apr 14 14:01:38 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lem_in.h"

static int	count_word(char *str, char cut)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == cut)
	j++;
      i++;
    }
  j++;
  return (j);
}

static int	count_in_word(char *str, char cut)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && str[i] != cut)
    i++;
  i++;
  return (i);
}

char		**my_str_to_wordtab(char *str, char cut)
{
  char		**tab;
  int		i;
  int		c;
  int		mv;

  i = 0;
  c = 0;
  tab = xmalloc((count_word(str, cut) + 1) * sizeof(char *));
  while (str[i])
    {
      mv = 0;
      tab[c] = xmalloc((count_in_word(str, cut) + 1) * sizeof(char));
      while (str[i] != cut && str[i] != '\0')
	tab[c][mv++] = str[i++];
      tab[c][mv] = '\0';
      if (str[i] == cut)
	i++;
      c++;
    }
  tab[c] = NULL;
  return (tab);
}

/*
** str_to_wordtab.c for str_to_wordtab in /home/lund/Bureau/Minishell
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Dec 19 12:27:03 2011 florian dewulf
** Last update Sun Apr 22 22:37:18 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lemin.h"

int		count(char *str, int *curseur)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[(*curseur)] == ' ' || str[(*curseur)] == '\t')
    (*curseur)++;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  if (str[0] == '\0' || str[i] == '\0')
    return (0);
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  j++;
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	}
      else
	i++;
    }
  j += (str[i - 1] != ' ' && str[i - 1] != '\t') ? 1 : 0;
  return (j);
}

static char	*complete_tab(char *tab, char *str, int *curseur)
{
  int		tmp;
  int		i;

  i = 0;
  tmp = *curseur;
  while (str[(*curseur)] != ' ' && str[(*curseur)] != '\t' && \
	 str[(*curseur)] != '\0')
    (*curseur)++;
  tab = xmalloc(((*curseur) - tmp + 1) * sizeof(char));
  while (tmp < (*curseur))
    {
      tab[i] = str[tmp];
      i++;
      tmp++;
    }
  tab[i] = '\0';
  while (str[(*curseur)] == ' ' || str[(*curseur)] == '\t')
    (*curseur)++;
  return (tab);
}

char	**str_to_wordtab(char *str)
{
  char	**tab;
  int	c;
  int	i;
  int	curseur;

  curseur = 0;
  i = 0;
  c = count(str, &curseur);
  tab = xmalloc((c + 1) * sizeof(char *));
  while (i < c)
    {
      tab[i] = complete_tab(tab[i], str, &curseur);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

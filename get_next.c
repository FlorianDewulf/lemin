#include	<stdlib.h>
#include	<stdio.h>
#include	"lemin.h"

char		*get_next_line(int fd)
{
  char		chaine[1024];
  char		*str;
  int		i;

  i = 0;
  str = fgets(chaine, sizeof(chaine), stdin);
  if (str == NULL)
    return (NULL);
  str = xmalloc((strlen(chaine) + 1) * sizeof(char));
  while (chaine[i] != '\n' && chaine[i] != '\0')
    str[i] = chaine[i++];
  str[i] = '\0';
  return (str);
}

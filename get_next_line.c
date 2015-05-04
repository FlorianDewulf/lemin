/*
** get_next_line.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Tue Apr 17 08:20:21 2012 kevin lansel
** Last update Sat Apr 21 17:26:27 2012 kevin lansel
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lem_in.h"

int		xread(int fd, void *buf, size_t count)
{
  int		x;

  x = read(fd, buf, count);
  if (x == -1)
    exit(EXIT_FAILURE);
  return (x);
}

char		*get_next_line(int fd)
{
  static int	i = BUFFER;
  static char	buff[BUFFER + 1];
  static int	ret;
  int		j;
  char		*str;

  j = 0;
  if (i >= BUFFER)
    {
      i = 0;
      ret = xread(fd, buff, BUFFER);
      buff[ret] = '\0';
    }
  if (i < BUFFER && buff[i] != '\0')
    {
      str = xmalloc(BUFFER * sizeof(char));
      while (buff[i] != '\n' && buff[i] != '\0')
	str[j++] = buff[i++];
      str[j] = '\0';
      if (buff[i] == '\n')
	i++;
      return (str);
    }
  return (NULL);
}

/*
** check2.c for lemin in /home/lund/Dossier courant/lem_in/test
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Apr 18 11:36:32 2012 florian dewulf
** Last update Sat Apr 21 17:29:02 2012 kevin lansel
*/

#include	<stdlib.h>
#include	"lemin.h"

static char	*cut_str(char *str, int begin, int end)
{
  char		*tmp;
  int		curs;

  curs = 0;
  tmp = xmalloc((end - begin + 1) * sizeof(char));
  while (str[begin] && begin < end)
    tmp[curs++] = str[begin++];
  tmp[curs] = '\0';
  return (tmp);
}

static char	*take_chain(char *str, int *curs, int *tmp)
{
  char		*dest;

  while (str[*curs] == ' ' || str[*curs] == '\t')
    (*curs)++;
  *tmp = *curs;
  while (str[*curs] != ' ' && str[*curs] != '\t' && str[*curs])
    (*curs)++;
  if (*tmp == *curs)
    return (NULL);
  dest = cut_str(str, *tmp, *curs);
  return (dest);
}

static int	isnum(char *str)
{
  int		curs;

  curs = -1;
  while (str[++curs])
    if (str[curs] < '0' || str[curs] > '9')
      return (1);
  return (0);
}

int		check_room(char *str, int pipe_ind)
{
  char		*tmp1;
  char		*tmp2;
  char		*tmp3;
  int		curs;
  int		tmp;

  if (pipe_ind != 0)
    my_puterror(USAGE);
  curs = -1;
  if (check_pres_link(str))
    return (0);
  while (str[++curs] == ' ' || str[curs] == '\t');
  tmp = curs;
  while (str[curs] != ' ' && str[curs] != '\t' && str[curs])
    curs++;
  if (tmp == curs)
    return (0);
  tmp1 = cut_str(str, tmp, curs);
  tmp2 = take_chain(str, &curs, &tmp);
  tmp3 = take_chain(str, &curs, &tmp);
  if (tmp2 == NULL || tmp3 == NULL)
    return (0);
  if (isnum(tmp2) || isnum(tmp3) || !check_valid_chars(tmp1, PATTERN))
    return (0);
  return (1);
}

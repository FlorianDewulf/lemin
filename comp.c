/*
** comp.c for lemin in /home/lund/Dossier courant/lem_in
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu Apr  5 13:30:42 2012 florian dewulf
** Last update Fri Apr 13 13:28:01 2012 florian dewulf
*/

#include	"lemin.h"

int		comp_to_char(char *str, int end, char *pattern)
{
  int	count;
  int	count_str;

  count_str = -1;
  while (str[++count_str] == ' ' || str[count_str] == '\t');
  if (count_str != -1)
    count_str--;
  count = -1;
  while (str[++count_str] && pattern[++count] && count < end)
    if (str[count_str] != pattern[count])
      return (0);
  while (pattern[count] == ' ' || pattern[count] == '\t')
    count++;
  if (count != end && str[count_str] && pattern[count])
    return (0);
  else
    return (1);
}

int		comp_from_char(char *str, int begin, char *pattern)
{
  int	count;

  count = 0;
  while (str[begin] == ' ' || str[begin] == '\t')
    begin++;
  while (str[begin] && pattern[count])
    if (str[begin] == pattern[count])
      {
	begin++;
	count++;
      }
    else
      return (0);
  if (pattern[count] == '\0')
    if (str[begin] == ' ' || str[begin] == '\t' || str[begin] == '\0')
      return (1);
    else
      return (0);
  else
    return (0);
}

int		comp(char *s1, char *s2)
{
  int		curs;

  curs = -1;
  if (my_strlen(s1) != my_strlen(s2))
    return (0);
  while (s1[++curs] && s2[curs])
    if (s1[curs] != s2[curs])
      return (0);
  if (!s1[curs] && !s2[curs])
    return (1);
  return (0);
}

int		check_valid_chars(char *str, char *pattern)
{
  int		curs_str;
  int		curs_path;
  int		indice;

  curs_str = -1;
  while (str[++curs_str])
    {
      indice = 0;
      curs_path = -1;
      while (pattern[++curs_path] && !indice)
	if (pattern[curs_path] == str[curs_str])
	  indice++;
      if (indice == 0)
	return (0);
    }
  return (1);
}

/*
** lem_in.h for  in /home/lund/Dossier courant/lem_in
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sat Apr  7 13:24:30 2012 florian dewulf
** Last update Sat Apr 21 17:45:27 2012 kevin lansel
*/

#ifndef		__LEMIN_H__
#define		__LEMIN_H__

#define		PATTERN		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define		ERROR_INSTRU	"We need an instruction \"##start\" and a \"##end\"\n"
#define		MISS_END	"Missing instruction \"##end\"\n"
#define		MISS_START	"Missing instruction \"##start\"\n"
#define		TOO_MANY_INSTR	"There is too many instruction \"##start\" or \"##end\"\n"
#define		NOVALID		"Un fichier valide fait au moins 6 lignes :\nnb\n##start\nroom\n##end\nroom\npipe\n)"
#define		FOLLOW_INSTRU	"An instruction must be following by a (valid) room\n"
#define		BENUMBER	"The first line must be a number(> 0)\n"
#define		STRANGE		"You have a strange line in your file, you know ?\n"
#define		USAGE		"Usage of the config file :\nnb ants\nRooms\nLink\n"
#define		NOLINK		"There is no link :O\n"
#define		NOROOM		"A room doesn't exist in the definition of the pipe\n"
#define		NOLINK_INSTRU	"There is no link with the start or/and the end\n"
#define		ERROR_FILE	"Error in the file\n"
#define		ERROR_SYNTAX	"Error syntax line number "
#define		FAIL_MALLOC	"Fail malloc\n"

struct		s_conf
{
  char		*line;
  int		where;
  struct s_conf *next;
  struct s_conf	*previous;
};

typedef struct s_conf t_conf;

int	check_alink(char *);
void	epur_and_sort(t_conf **);
int	check_post_pipe(char *);
void	navig_to_link(t_conf **);
void	check_pre_list(t_conf **);
void	my_putstr(char *);
void	my_putchar(char);
int	my_strlen(char *);
int	free_tab(char **);
void	my_puterror(char *);
void	put_error_line(int);
char	*concate(char *, char *);
int	comp_to_char(char *, int, char *);
int	comp_from_char(char *, int, char *);
int	comp(char *, char *);
int	check_valid_chars(char *, char *);
int	check_valid_pipe(char **, t_conf **);
void	check_link(t_conf **);
int	check_com(char *);
int	check_room(char *, int);
int	check_pipe_valid(char *);
int	check_pipe(char *);
int	check_instruction(char *);
void	remove_com(t_conf **, t_conf **);
void	my_puterror(char *);
void	put_error_line(int);
char	*modif_pipe(char *);
char	**str_to_wordtab(char *);
void	check_list(t_conf **);
void	*xmalloc(int);
int	check_pres_link(char *);
void	move_maille(t_conf **, int, char *);
void	suppr_double(t_conf **);
int	space_check(char *);
void	game(t_conf *);

#endif

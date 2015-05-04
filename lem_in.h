/*
** lem_in.h for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Mon Apr  2 14:07:17 2012 kevin lansel
** Last update Sun Apr 22 21:50:10 2012 kevin lansel
*/

#ifndef		__LEM_IN_H__
#define		__LEM_IN_H__

#define		BUFFER		1024

/*
** ERROR
*/

#define		READ	"Error read\n"
#define		MALLOC	"Error malloc\n"
#define		START	"No room after START\n"

/*
** STRUCT LEM_IN
*/

struct		t_lem;

typedef struct	s_lem *ptr;

typedef struct	s_link
{
  ptr		way;
  struct s_link	*next;
  struct s_link	*prev;
}		t_link;

typedef struct	s_lem
{
  char		*name;
  int		x;
  int		y;
  int		time;
  int		view;
  int		full;
  t_link	*link;
  struct s_lem	*prev;
  struct s_lem	*next;
}		t_lem;

typedef struct	s_road
{
  t_lem		*rway;
  struct s_road	*next;
  struct s_road	*prev;
}		t_road;

/*
** PROTOTYPE LEM_IN
*/

int		my_strlen(char *);
void		my_putchar(char);
void		my_putstr(char *);
void		my_puterror(char *);
int		my_getnbr(char *);
int		my_strcmp(char *, char *);
void		my_strcpy(char *, char *);
int		my_match(char *, char);
void		*xmalloc(int);
char		**my_str_to_wordtab(char *, char);
char		*get_next_line(int);
void		list_graph_init(t_lem **, char *);
void		list_link_init(t_lem *, t_lem *);
t_road		*list_road_init(t_road *, t_lem *);
void		add_to_end_graph(t_lem **, t_lem *);
void		add_to_end_link(t_lem *, t_link *);
t_road		*add_to_end_road(t_road *, t_road *);
void		link_room(t_lem **, t_lem *, t_lem *);
void		way(int, t_lem *);
void		road(t_lem *, int);
void		my_road1(t_road *, int, t_link *);
void		my_road2(t_road *, int, t_link *);
t_lem		*link_road1(t_link *, int *);
t_lem		*link_road2(t_link *, int *);
void		show_list(t_lem *);
void		show_link(t_lem *);
void		show_road(t_road *);
t_road		*check_road1(t_road *);
t_road		*check_road2(t_road *);
void		move_ants(int, t_road *, t_road *);
t_road		*end_road(t_road *);
void		one_road(int, t_road *, int, t_road *);
void		two_road(int, t_road *, t_road *, int);

#endif

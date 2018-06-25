/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 15:46:36 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 12:54:29 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct		s_opt
{
	size_t			len;
	int				graph;
	int				nbr;
	int				fd;
}					t_opt;

typedef struct		s_fun
{
	char			*str;
	void			(*ptr)();
}					t_fun;

typedef struct		s_parse
{
	size_t			min;
	size_t			max;
	size_t			len;
	size_t			rot;
	int				med;
	int				side;
}					t_parse;

typedef struct		s_tab
{
	int				*tab;
	size_t			len;
}					t_tab;

int					check_file(int argc, char **argv);
int					*create_tab(int argc, char **argv, t_opt *top);

int					print_error(void);
void				print_do(t_tab *taba, t_tab *tabb, char *str);

int					is_sort(t_tab *taba);
int					is_invsort(t_tab *taba);

int					find_median(t_tab *taba, t_tab *tabb, t_parse parse);

void				sort_spec(t_tab *taba, t_tab *tabb);
void				split(t_tab *taba, t_tab *tabb, t_parse parse);
void				create_parse(t_parse *lap, t_parse parse);

void				sa(t_tab *taba, t_tab *tabb);
void				sb(t_tab *taba, t_tab *tabb);
void				ss(t_tab *taba, t_tab *tabb);
void				ra(t_tab *taba, t_tab *tabb);
void				rb(t_tab *taba, t_tab *tabb);
void				rr(t_tab *taba, t_tab *tabb);
void				rra(t_tab *taba, t_tab *tabb);
void				rrb(t_tab *taba, t_tab *tabb);
void				rrr(t_tab *taba, t_tab *tabb);
void				pa(t_tab *taba, t_tab *tabb);
void				pb(t_tab *taba, t_tab *tabb);

#endif

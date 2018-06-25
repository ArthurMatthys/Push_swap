/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 18:15:00 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 18:26:08 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

void	init_fun(t_fun *fun)
{
	fun[0].str = "sa";
	fun[0].ptr = &sa;
	fun[1].str = "sb";
	fun[1].ptr = &sb;
	fun[2].str = "ss";
	fun[2].ptr = &ss;
	fun[3].str = "ra";
	fun[3].ptr = &ra;
	fun[4].str = "rb";
	fun[4].ptr = &rb;
	fun[5].str = "rr";
	fun[5].ptr = &rr;
	fun[6].str = "rra";
	fun[6].ptr = &rra;
	fun[7].str = "rrb";
	fun[7].ptr = &rrb;
	fun[8].str = "rrr";
	fun[8].ptr = &rrr;
	fun[9].str = "pa";
	fun[9].ptr = &pa;
	fun[10].str = "pb";
	fun[10].ptr = &pb;
}

int		srch_fun(char *buff, t_fun *fun)
{
	int i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp((char *)buff, fun[i].str))
			return (i);
		i++;
	}
	return (-1);
}

int		opp_on_tab(t_tab *taba, t_tab *tabb, t_fun *fun)
{
	int		i;
	size_t	j;
	char	*str;

	j = 0;
	while (get_next_line(0, &str))
	{
		i = srch_fun(str, fun);
		if (i == -1)
		{
			free(str);
			return (print_error());
		}
		fun[i].ptr(&(*taba), &(*tabb));
		free(str);
	}
	free(str);
	free_fd();
	return (1);
}

int		main(int argc, char **argv)
{
	t_tab		taba;
	t_tab		tabb;
	t_opt		top;
	t_fun		fun[11];

	if (!check_file(argc, argv))
		return (0);
	if (!(taba.tab = create_tab(argc, argv, &top)))
		return (print_error());
	init_fun(fun);
	tabb.tab = (int *)malloc(sizeof(int) * (top.len));
	tabb.len = 0;
	taba.len = top.len;
	if (!(opp_on_tab(&taba, &tabb, fun)))
		;
	else if (!(is_sort(&taba)))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(taba.tab);
	free(tabb.tab);
	return (1);
}

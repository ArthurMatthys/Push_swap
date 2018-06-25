/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/25 10:44:16 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 10:55:16 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

void	split_2(t_tab *taba, t_tab *tabb, t_parse parse)
{
	size_t	i;

	i = 0;
	if (parse.len == 1 && parse.side)
		print_do(taba, tabb, "pa");
	else if (parse.len == 1 && !parse.side)
		;
	else if (parse.len <= 2 && parse.side)
	{
		if (tabb->tab[0] < tabb->tab[1])
			print_do(taba, tabb, "sb");
		while (i++ < parse.len)
			print_do(taba, tabb, "pa");
	}
	else if (parse.len <= 2 && !parse.side)
	{
		if (taba->tab[0] > taba->tab[1])
			print_do(taba, tabb, "sa");
	}
}

void	split_left(t_tab *taba, t_tab *tabb, t_parse parse)
{
	size_t	tmp;
	size_t	i;

	i = 0;
	tmp = 0;
	while (tmp < parse.len / 2)
	{
		if (taba->tab[parse.min] <= parse.med)
		{
			print_do(taba, tabb, "pb");
			tmp++;
		}
		else
		{
			print_do(taba, tabb, "ra");
			parse.rot++;
			i++;
		}
	}
	while (parse.rot--)
		print_do(taba, tabb, "rra");
}

void	split_right(t_tab *taba, t_tab *tabb, t_parse parse)
{
	size_t	tmp;
	size_t	i;

	i = 0;
	tmp = 0;
	while (tmp < (parse.len + 1) / 2)
	{
		if (tabb->tab[parse.min] > parse.med)
		{
			print_do(taba, tabb, "pa");
			tmp++;
		}
		else
		{
			print_do(taba, tabb, "rb");
			parse.rot++;
			i++;
		}
	}
	while (parse.rot--)
		print_do(taba, tabb, "rrb");
}

void	split(t_tab *taba, t_tab *tabb, t_parse parse)
{
	t_parse	lap[2];

	create_parse(lap, parse);
	if (parse.len <= 2)
		split_2(taba, tabb, parse);
	else if (!parse.side)
		split_left(taba, tabb, parse);
	else
		split_right(taba, tabb, parse);
	lap[0].med = find_median(taba, tabb, lap[0]);
	lap[1].med = find_median(taba, tabb, lap[1]);
	if (parse.len > 2 && !is_sort(taba))
		split(taba, tabb, lap[0]);
	if (parse.len > 2 && !is_invsort(tabb))
		split(taba, tabb, lap[1]);
}

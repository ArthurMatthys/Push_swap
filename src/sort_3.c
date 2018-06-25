/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_3.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/24 14:01:37 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 10:34:45 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	sort_3(t_tab *taba, t_tab *tabb)
{
	if (taba->tab[0] > taba->tab[1] && taba->tab[1] > taba->tab[2])
	{
		print_do(taba, tabb, "ra");
		print_do(taba, tabb, "sa");
	}
	else if (taba->tab[0] < taba->tab[1] && taba->tab[1] < taba->tab[2])
		;
	else if (taba->tab[0] > taba->tab[1] && taba->tab[1] < taba->tab[2] &&
			taba->tab[0] > taba->tab[2])
		print_do(taba, tabb, "ra");
	else if (taba->tab[0] < taba->tab[1] && taba->tab[1] > taba->tab[2] &&
			taba->tab[0] < taba->tab[2])
	{
		print_do(taba, tabb, "ra");
		print_do(taba, tabb, "sa");
		print_do(taba, tabb, "rra");
	}
	else if (taba->tab[0] > taba->tab[1] && taba->tab[1] < taba->tab[2])
		print_do(taba, tabb, "sa");
	else
		print_do(taba, tabb, "rra");
}

int		mid(t_tab *taba)
{
	size_t	i;
	size_t	j;
	int		tmp;
	int		count;

	i = 0;
	while (i < taba->len)
	{
		tmp = taba->tab[i];
		j = 0;
		count = 0;
		while (j < taba->len)
		{
			if (taba->tab[j] <= tmp)
				count++;
			j++;
		}
		if (count == 3)
			break ;
		i++;
	}
	return (tmp);
}

void	sort_5(t_tab *taba, t_tab *tabb)
{
	int	med;

	med = mid(taba);
	while (taba->len > 3)
	{
		if (taba->tab[0] < med)
			print_do(taba, tabb, "pb");
		else
			print_do(taba, tabb, "ra");
	}
	if (tabb->tab[0] < tabb->tab[1])
		print_do(taba, tabb, "sb");
	sort_3(taba, tabb);
	while (tabb->len)
		print_do(taba, tabb, "pa");
}

void	sort_spec(t_tab *taba, t_tab *tabb)
{
	if (taba->len == 3)
		return (sort_3(taba, tabb));
	else
		return (sort_5(taba, tabb));
}

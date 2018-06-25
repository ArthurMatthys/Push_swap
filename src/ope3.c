/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ope3.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 11:31:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 18:35:56 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_tab *taba, t_tab *tabb)
{
	size_t	i;
	int		j;

	i = taba->len - 1;
	(void)tabb;
	if (taba->len)
	{
		j = taba->tab[i];
		while (i > 0)
		{
			taba->tab[i] = taba->tab[i - 1];
			i--;
		}
		taba->tab[i] = j;
	}
}

void	rrb(t_tab *taba, t_tab *tabb)
{
	size_t	i;
	int		j;

	(void)taba;
	i = tabb->len - 1;
	if (tabb->len)
	{
		j = tabb->tab[i];
		while (i > 0)
		{
			tabb->tab[i] = tabb->tab[i - 1];
			i--;
		}
		tabb->tab[i] = j;
	}
}

void	rrr(t_tab *taba, t_tab *tabb)
{
	rra(taba, tabb);
	rrb(taba, tabb);
}

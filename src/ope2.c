/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ope2.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 10:57:11 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 14:12:15 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

void		ra(t_tab *taba, t_tab *tabb)
{
	size_t	i;
	int		j;

	(void)tabb;
	i = 0;
	if (taba->len)
	{
		j = taba->tab[0];
		while (i < taba->len - 1)
		{
			taba->tab[i] = taba->tab[i + 1];
			i++;
		}
		taba->tab[i] = j;
	}
}

void		rb(t_tab *taba, t_tab *tabb)
{
	size_t	i;
	int		j;

	(void)taba;
	i = 0;
	if (tabb->len)
	{
		j = tabb->tab[0];
		while (i < tabb->len - 1)
		{
			tabb->tab[i] = tabb->tab[i + 1];
			i++;
		}
		tabb->tab[i] = j;
	}
}

void		rr(t_tab *taba, t_tab *tabb)
{
	ra(&(*taba), &(*tabb));
	rb(&(*taba), &(*tabb));
}

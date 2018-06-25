/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ope1.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 09:18:35 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 16:18:28 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_tab *taba, t_tab *tabb)
{
	int		tmp;

	(void)tabb;
	if (taba->len > 1)
	{
		tmp = taba->tab[0];
		taba->tab[0] = taba->tab[1];
		taba->tab[1] = tmp;
	}
}

void	sb(t_tab *taba, t_tab *tabb)
{
	int		tmp;

	(void)taba;
	if (tabb->len > 1)
	{
		tmp = tabb->tab[0];
		tabb->tab[0] = tabb->tab[1];
		tabb->tab[1] = tmp;
	}
}

void	ss(t_tab *taba, t_tab *tabb)
{
	sa(&(*taba), &(*tabb));
	sb(&(*taba), &(*tabb));
}

void	pa(t_tab *taba, t_tab *tabb)
{
	size_t	i;

	i = taba->len;
	if (tabb->len)
	{
		while (i > 0)
		{
			taba->tab[i] = taba->tab[i - 1];
			i--;
		}
		taba->tab[0] = tabb->tab[0];
		while (i < tabb->len - 1)
		{
			tabb->tab[i] = tabb->tab[i + 1];
			i++;
		}
		taba->len++;
		tabb->len--;
	}
}

void	pb(t_tab *taba, t_tab *tabb)
{
	size_t	i;

	i = tabb->len;
	if (taba->len)
	{
		while (i > 0)
		{
			tabb->tab[i] = tabb->tab[i - 1];
			i--;
		}
		tabb->tab[0] = taba->tab[0];
		while (i < taba->len - 1)
		{
			taba->tab[i] = taba->tab[i + 1];
			i++;
		}
		tabb->len++;
		taba->len--;
	}
}

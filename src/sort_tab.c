/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_tab.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/21 10:28:38 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/21 10:39:34 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		is_sort(t_tab *taba)
{
	size_t i;

	i = 0;
	while (i < taba->len - 1)
	{
		if (taba->tab[i] > taba->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		is_invsort(t_tab *taba)
{
	size_t i;

	i = 0;
	while (i < taba->len - 1)
	{
		if (taba->tab[i] < taba->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

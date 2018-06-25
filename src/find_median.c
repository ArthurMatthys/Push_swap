/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fimd_median.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/20 09:08:36 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 09:50:25 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		in_taba(t_tab *taba, t_parse parse)
{
	int		res;
	size_t	inf;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < parse.len)
	{
		inf = 0;
		j = 0;
		res = taba->tab[parse.min + i];
		while (j < parse.len)
		{
			if (taba->tab[parse.min + j] <= res)
				inf++;
			j++;
		}
		if (inf == ((parse.len) / 2))
			break ;
		i++;
	}
	return (res);
}

int		in_tabb(t_tab *tabb, t_parse parse)
{
	int		res;
	size_t	inf;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < parse.len)
	{
		inf = 0;
		j = 0;
		res = tabb->tab[parse.min + i];
		while (j < parse.len)
		{
			if (tabb->tab[parse.min + j] <= res)
				inf++;
			j++;
		}
		if (inf == ((parse.len) / 2))
			break ;
		i++;
	}
	return (res);
}

int		find_median(t_tab *taba, t_tab *tabb, t_parse parse)
{
	size_t j;

	j = 0;
	if (!parse.side)
		return (in_taba(taba, parse));
	else
		return (in_tabb(tabb, parse));
}

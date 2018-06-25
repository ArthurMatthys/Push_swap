/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_op.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/23 17:43:32 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 12:51:09 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

void	first_fun(t_tab *taba, t_tab *tabb, char *str)
{
	if (!ft_strcmp(str, "pa"))
	{
		write(1, "pa\n", 3);
		pa(&(*taba), &(*tabb));
	}
	else if (!ft_strcmp(str, "pb"))
	{
		write(1, "pb\n", 3);
		pb(&(*taba), &(*tabb));
	}
	else if (!ft_strcmp(str, "rra"))
	{
		write(1, "rra\n", 4);
		rra(&(*taba), &(*tabb));
	}
	else
	{
		write(1, "rrb\n", 4);
		rrb(&(*taba), &(*tabb));
	}
}

void	print_do(t_tab *taba, t_tab *tabb, char *str)
{
	if (!ft_strcmp(str, "ra"))
	{
		write(1, "ra\n", 3);
		ra(&(*taba), &(*tabb));
	}
	else if (!ft_strcmp(str, "rb"))
	{
		write(1, "rb\n", 3);
		rb(&(*taba), &(*tabb));
	}
	else if (!ft_strcmp(str, "sa"))
	{
		write(1, "sa\n", 3);
		sa(&(*taba), &(*tabb));
	}
	else if (!ft_strcmp(str, "sb"))
	{
		write(1, "sb\n", 3);
		sb(&(*taba), &(*tabb));
	}
	else
		first_fun(taba, tabb, str);
}

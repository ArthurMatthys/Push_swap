/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 15:46:08 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 13:57:59 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

void	*conv_argv_tab(int argc, char **argv, t_opt *top)
{
	int			i;
	intmax_t	j;
	int			*tab;

	i = 1;
	tab = (int *)malloc(sizeof(int) * (argc - 1));
	if (!tab)
		return (NULL);
	while (i < argc)
	{
		j = ft_atoi(argv[i]);
		if (j > INT_MAX || j < INT_MIN || is_in(j, tab, i))
		{
			free(tab);
			return (NULL);
		}
		else
			tab[i - 1] = (int)j;
		i++;
	}
	top->len = (size_t)(i - 1);
	return (tab);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_memdel((void **)&(tab[i]));
		i++;
	}
	ft_memdel((void **)tab);
	free(tab);
}

void	*inner_fun(char **tab, int *res)
{
	free_tab(tab);
	free(res);
	return (NULL);
}

void	*conv_str_tab(char *str, t_opt *top)
{
	size_t		i;
	size_t		t;
	int			*res;
	intmax_t	j;
	char		**tab;

	i = 0;
	t = 0;
	if (!(tab = ft_strsplit(str, ' ')))
		return (NULL);
	while (tab[i])
		i++;
	res = (int *)malloc(sizeof(int) * i);
	while (t < i && tab[t])
	{
		j = ft_atoi(tab[t]);
		if (j > INT_MAX || j < INT_MIN || is_in(j, res, t))
			return (inner_fun(tab, res));
		else
			res[t] = (int)j;
		t++;
	}
	top->len = i;
	free_tab(tab);
	return (res);
}

int		*create_tab(int argc, char **argv, t_opt *top)
{
	if (argc > 2)
		return (conv_argv_tab(argc, argv, &(*top)));
	else
		return (conv_str_tab(argv[1], &(*top)));
}

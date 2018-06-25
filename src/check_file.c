/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_file.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 14:16:53 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 12:51:57 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		print_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int		check_string(char *str)
{
	size_t	i;

	i = 1;
	if (str[0] && !ft_isdigit(str[0]) && str[0] != '-')
		return (print_error());
	while (str[i])
	{
		if ((str[i] == ' ' && ft_isdigit(str[i - 1])) || ft_isdigit(str[i]) ||
				(str[i] == '-' && (str[i - 1] == ' ' || !i)))
			i++;
		else
			return (print_error());
	}
	if (str[i - 1] == ' ')
		return (print_error());
	return (1);
}

int		check_tab(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][0] == '-')
				j++;
			else if (!ft_isdigit(argv[i][j]))
				return (print_error());
			else
				j++;
		}
		i++;
	}
	return (1);
}

int		check_file(int argc, char **argv)
{
	if (argc == 1)
		return (print_error());
	else if (argc == 2)
		return (check_string(argv[1]));
	else
		return (check_tab(argc, argv));
}

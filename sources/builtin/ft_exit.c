/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:41:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/18 16:25:28 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	check_arg_count(const char **av)
{
	int	ac;

	ac = 0;
	while (*(av++))
	{
		++ac;
		if (ac > 1)
		{
			ft_putendl_fd(PROJECT_NAME ": exit: too many arguments", 2);
			exit(1);
		}
	}
}

static void	check_arg_format(const char *av)
{
	const char	*tmp;

	tmp = av;
	while (*tmp)
	{
		if (!ft_isdigit(*(tmp++)))
		{
			ft_putstr_fd(PROJECT_NAME ": exit: ", 2);
			ft_putstr_fd(av, 2);
			ft_putendl_fd(": numeric argument required", 2);
			exit(255);
		}
	}
}

int			ft_exit(const char **av)
{
	char		res;

	if (av && *av)
	{
		check_arg_count(av);
		check_arg_format(*av);
		res = (char)ft_atoi(*av);
		exit(res);
	}
	exit(g_res_exec);
}

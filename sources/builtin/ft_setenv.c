/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/16 20:50:42 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

int			ft_setenv(const char **av)
{
	extern	char	**environ;

	if (!environ)
		return (1);
	while (*av)
	{
		set_var(*av, &environ, 0);
		++av;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 12:31:45 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/27 17:21:19 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		zero_hendler(const char *str, int *j)
{
	t_uchar	c;
	int		i;
	char	tmp[3];

	i = 0;
	*j += 1;
	while (i < 3)
		tmp[i++] = '\0';
	i = 0;
	while (str[*j] && i < 3 && str[*j] >= '0' && str[*j] <= '7')
	{
		tmp[i] = str[*j];
		i++;
		*j += 1;
	}
	*j -= 1;
	if (tmp[0] == '\0')
		return ;
	c = ft_atoi_octal(tmp, &i);
	write(1, &c, 1);
}

int			echo_hendler(const char *command, int *j)
{
	*j += 1;
	if (command[*j] == 'a')
		write(1, "\a", 1);
	else if (command[*j] == 'b')
		write(1, "\b", 1);
	else if (command[*j] == 'f')
		write(1, "\f", 1);
	else if (command[*j] == 'n')
		write(1, "\n", 1);
	else if (command[*j] == 'r')
		write(1, "\r", 1);
	else if (command[*j] == 't')
		write(1, "\t", 1);
	else if (command[*j] == 'v')
		write(1, "\v", 1);
	else if (command[*j] == 'c')
		return (0);
	else if (command[*j] == '0')
		zero_hendler(command, j);
	else if (command[*j] == '\\')
		return (-1);
	else
		write(1, &command[*j - 1], 2);
	return (1);
}

static int	ft_options_contr(const char **command, int *i)
{
	int		j;

	j = 1;
	while (command[*i][j] == 'n')
		j++;
	if (command[*i][j])
		return (-1);
	*i += 1;
	return (1);
}

static int	ft_writer_contr(const char **command, int i, int l, int j)
{
	while (command[i][j])
	{
		if (command[i][j] == '\\')
		{
			if (command[i][j + 1])
				l = echo_hendler(command[i], &j);
			if (l == 0)
				return (-1);
			else if ((command[i][j] && command[i][j] == '\\'
					&& !command[i][j + 1]) || l == -1)
				write(1, "\\", 1);
		}
		else
			write(1, &command[i][j], 1);
		j++;
	}
	if (command[i + 1])
		write(1, " ", 1);
	return (1);
}

int			ft_echo(const char **command)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	if (command[i] == NULL)
	{
		write(1, "\n", 1);
		return (1);
	}
	if (write(1, command[i], 0))
		print_error("echo: ", "write error: Bad file descriptor");
	while (command[i] && command[i][0] == '-')
		if ((flag = ft_options_contr(command, &i)) == -1)
			break ;
	if (command[i] == NULL)
		return (1);
	while (command[i])
		if (ft_writer_contr(command, i++, -12, 0) < 0)
			return (0);
	if (flag != 1)
		write(1, "\n", 1);
	return (1);
}

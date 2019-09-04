/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_completions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:11:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 19:31:13 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	get_max_len(char **arr, int n)
{
	int			i;
	int			max;
	int			len;

	max = 0;
	i = -1;
	while (++i < n)
	{
		len = ft_strlen(arr[i]);
		if (len > max)
			max = len;
	}
	return (max);
}

static void	show_one(char *str, int max)
{
	int i;

	ft_putstr_fd(str, STDOUT);
	i = ft_strlen(str);
	while (i++ < max)
	{
		if (i >= get_screen_width())
			break ;
		ft_putchar_fd(' ', STDOUT);
	}
}

static void	show(char **arr, int n)
{
	int max_len;
	int columns;
	int jump;
	int row;
	int i;

	ft_putstr_fd("\n\r", STDOUT);
	max_len = get_max_len(arr, n) + 2;
	columns = get_screen_width() / max_len;
	columns = (columns == 0 ? 1 : columns);
	jump = n / columns;
	if (n % columns)
		jump++;
	row = 0;
	while (row < jump)
	{
		i = row;
		while (i < n)
		{
			show_one(arr[i], max_len);
			i += jump;
		}
		ft_putstr_fd("\n\r", STDOUT);
		row++;
	}
}

static int	ask_display_many(int n)
{
	char	c;

	if (n < COMPLETION_QUERY_ITEMS)
		return (1);
	ft_fdprintf(STDOUT, "\n\rDisplay all %d possibilities? (y or n)", n);
	c = 0;
	while (c != CTRL_C && c != 'n' && c != DEL)
	{
		read(STDIN, &c, 1);
		if (c == 'y' || c == ' ')
			return (1);
	}
	return (0);
}

void		show_completions(char **arr, int n)
{
	if (n == 0)
		return ;
	if (ask_display_many(n))
		show(arr, n);
	else
		ft_putstr_fd("\n\r", STDOUT);
}

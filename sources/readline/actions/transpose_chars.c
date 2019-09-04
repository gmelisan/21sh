/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:12:44 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 17:29:24 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static void	swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		transpose_chars(t_line *line)
{
	int		pos;

	if (line->cpos == 0 || line->str->len <= 1)
		return ;
	pos = line->cpos;
	if (line->cpos == (int)line->str->len)
		swap(&line->str->s[pos - 2], &line->str->s[pos - 1]);
	else
		swap(&line->str->s[pos - 1], &line->str->s[pos]);
	forward_char(line);
	push_undo_list(line);
}

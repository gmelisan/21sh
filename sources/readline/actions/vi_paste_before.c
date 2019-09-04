/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_paste_before.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 03:50:03 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 19:31:29 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_paste_before(t_line *line)
{
	int i;

	if (line->kill_buffer.len > 0)
	{
		i = -1;
		while (++i < line->arg)
		{
			str_xinsert(line->str, line->cpos,
						line->kill_buffer.s, line->kill_buffer.len);
			line->cpos += line->kill_buffer.len;
		}
		line->cpos--;
	}
}

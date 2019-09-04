/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:17:38 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/27 17:27:58 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

extern t_opt	g_opt;

int				get_term_cols(void)
{
	struct winsize	ws;

	ioctl(STDIN, TIOCGWINSZ, &ws);
	if (!ws.ws_col || ws.ws_col > TERM_MAX_COL)
		return (TERM_MAX_COL);
	return (ws.ws_col);
}

t_string		*build_bufout(t_string str, int width)
{
	int			rows;
	t_string	*res;
	int			i;
	int			j;

	rows = str.len / width + 1;
	res = ft_xmemalloc(sizeof(t_string) * (rows + 1));
	i = -1;
	while (++i < rows)
	{
		res[i] = str_xcreate(width);
		j = -1;
		while (++j < (int)res[i].len)
			res[i].s[j] = str_get(str, width * i + j);
		str_fixlen(res + i);
	}
	return (res);
}

static void		convert_nl(t_buffer *buf, int width)
{
	int	i;
	int j;
	int	add;
	int from;

	add = 0;
	i = -1;
	from = 0;
	while (str_get(buf->b, ++i))
	{
		if (str_get(buf->b, i) == '\n')
		{
			add = (width - (i % width)) - 1;
			from = i + 1;
			shift_escseq(&buf->escseqs, from, add);
			buf->b.s[i] = ' ';
			j = 0;
			while (++j < (width - (i % width)))
				str_xinsert(&buf->b, i, " ", 1);
		}
	}
}

static void		build_newbuf(t_buffer *newbuf, t_line *line, int cols)
{
	if (!line)
	{
		newbuf->b = str_xduplicate(g_buffer.original);
		newbuf->original = str_xduplicate(g_buffer.original);
		newbuf->cpos = g_buffer.cpos;
	}
	else
	{
		newbuf->original = str_xduplicate(*line->str);
		str_xaddfront(&newbuf->original, line->prompt.s, line->prompt.len);
		newbuf->b = str_xduplicate(newbuf->original);
		newbuf->cpos = g_buffer.prompt_len + line->cpos;
	}
	colorize(&newbuf->b, g_buffer.prompt_full_len);
	pull_escseqs(&newbuf->escseqs, &newbuf->b);
	if (!g_opt.enable_color)
		vec_delete(&newbuf->escseqs, del_str);
	convert_nl(newbuf, cols);
	newbuf->prompt_len = g_buffer.prompt_len;
	newbuf->prompt_full_len = g_buffer.prompt_full_len;
	newbuf->out_rows = newbuf->b.len / cols + 1;
	newbuf->out_cols = cols;
	newbuf->out = build_bufout(newbuf->b, cols);
}

/*
** Idea as in the original Readline lib.
** Two buffers:
** - `g_buffer' is what on the screen now.
** - `newbuf' builded from `line', what we want our screen to be.
** We update screen using `newbuf' and in the end put its contents
** to `g_buffer'.
*/

void			update_line(t_line *line)
{
	t_buffer	newbuf;
	int			cols;

	cols = get_term_cols();
	build_newbuf(&newbuf, line, cols);
	if (line)
		redisplay(&newbuf);
	else
		resize(&newbuf);
	clear_linebuf();
	ft_memcpy(&g_buffer, &newbuf, sizeof(t_buffer));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:45:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/27 19:21:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "parser.h"
#include "exec.h"

void		main_loop(void)
{
	t_pars_list	*list;
	char		*buf;
	char		*tmp;

	while (21)
	{
		g_check_nl = 1;
		if (!(buf = ft_readline(get_value_from_all_vars("PS1"), NULL)))
			break ;
		ft_putstr("\n");
		if (*(tmp = ft_strtrim(buf)))
		{
			list = exec_ast(buf);
			traverse_ast(list);
			g_error_pars = 0;
			parser_free_tree(list);
		}
		else
			free(buf);
		free(tmp);
	}
}

int			main(int argc, char *argv[])
{
	shell_init(argc, argv);
	main_loop();
	shell_clear();
	return (g_res_exec);
}

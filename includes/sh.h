/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:44:12 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/27 19:21:25 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <sys/wait.h>
# include <pwd.h>
# include "defs.h"
# include "libft.h"
# include "ast.h"
# include "hash.h"
# include "ft_readline.h"
# include "variables.h"
# include "lib_wtalea.h"
# include "xfuncs.h"

t_pars_list		*exec_ast(char *buf);
void			shell_init(int argc, char *argv[]);
void			shell_clear(void);

typedef struct	s_opt
{
	t_uint		vi_mode;
	t_uint		enable_color;
	t_uint		noclobber;
}				t_opt;

int				g_check_nl;

#endif

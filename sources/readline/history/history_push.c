/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:35:21 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/22 21:17:29 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void		history_push(t_history *history, t_string str)
{
	t_dlist *new;

	if (history->size >= history->max_size)
	{
		ft_dlstdelfront(&history->item, del_hist);
		history->size--;
		history->start_index++;
	}
	new = ft_dlstnew(&str, sizeof(str));
	ft_dlstaddback(&history->item, new);
	history->size++;
}

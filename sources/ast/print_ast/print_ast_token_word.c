/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_token_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 22:59:42 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/18 22:59:55 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ast.h"

void	print_ast_token_word(char *word)
{
	ft_putstr("\'");
	ft_putstr(word);
	ft_putstr("\'");
}
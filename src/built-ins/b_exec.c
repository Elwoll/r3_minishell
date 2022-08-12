/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:31:10 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/12 14:56:49 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_built_ins(t_main *main, t_cell *cur, int icmd)
{
	if (icmd == 1 && main->proc.ncmd == 1)
	{
		cur = avoid_redir(cur, icmd);
		if (ft_strncmp(cur->data, "exit", ft_strlen("exit")) == 0)
		{
			if (b_exit(main, cur, icmd) == 1)
				return (0);
		}
		else if (ft_strcmp_case(cur->data, "cd") == 0)
		{
			if (b_cd(main, cur, icmd) == 0)
				return (0);
		}
	}
	return (1);
}
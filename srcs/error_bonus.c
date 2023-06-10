/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:55:21 by dajeon            #+#    #+#             */
/*   Updated: 2023/06/10 17:47:01 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_perror_arg_bonus(char *name, int cur, int need)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": Need at least ", 2);
	ft_putnbr_fd(need, 2);
	ft_putstr_fd(" variable. You: ", 2);
	ft_putnbr_fd(cur, 2);
	ft_putendl_fd("", 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:37 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/31 15:36:18 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
	Input Mode
	In:
		-char **av: arguments
	Out: 
		-int entry:
			-entry == 1 if entry is in "<" mode
			-entry == 2 if entry is in "<<" mode
*/
int	input_mode(char **av)
{
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		return (2);
	return (1);
}

/*
	Is AV Correct ?
	This function will check if:
		-the file names (in and out) are empty
		-the commands are empty (no matter their position in the pipe line)
	In:
		-int ac: arguments number
	Out:
		-0 if problem
		-1 if correct
*/
int is_av_correct(int ac, char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	if (i != ac)
		return (0);	
	return (1);
}
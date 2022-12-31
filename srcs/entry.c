/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:18:27 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/31 17:55:59 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
	Read File
	This function will read the file given as the first parameter of AV, and
	return a string contaning its content
	In:
		-char *file_name: file name if in current directory, else path to file
	Out:
		-NULL: file is empty / not found
		-A string containing the content of the file
*/
static char	*read_file(char *file_name)
{
	int		i;
	int		fd;
	char	*file_content;
	char	*tmp;
	char	*tmp2;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file_content = ft_strdup("");
	if (!file_content)
		return (NULL);
	tmp = get_next_line(fd);
	while (tmp)
	{
		//Can be optimized
		tmp2 = ft_strdup(file_content);
		free(file_content);
		file_content = ft_strjoin(tmp2, tmp);
		free(tmp);
		free(tmp2);
		tmp = get_next_line(fd);
	}
	free(tmp);
	return (file_content);
}

/* 
	Read Standard
	This function will read the entry on the standard entry
	In:
		None
	Out:
		-NULL: entry is empty
		-A string containing the content of the standard input
*/
static char	*read_standard(void)
{
	return (NULL);
}


/*
	Read Entry
	This function will be able to choose whether Read File if the input is a
	file of Read Standard if the input is on the standard input (here_doc)
	In:
		-int entry:
			-1 if entry on file
			-2 if entry on standard input
	Out: char *
		-NULL if empty / error / not found
		-A string containing the content of the entry
		
*/
char		*read_entry(int entry, char *file_name)
{
	if (entry == 1)
		return (read_file(file_name));
	else if (entry == 2)
		return (read_standard());
	return (NULL);
}

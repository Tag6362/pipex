/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:18:27 by tgernez           #+#    #+#             */
/*   Updated: 2023/01/02 15:58:31 by tgernez          ###   ########.fr       */
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
	Read Standard Empty Limiter
	This function is a dependency of Read Standard, to deal with the case
	of an empty limiter
	Will take the input on the standard entry until the given line by the user
	is empty.
	In:
		None
	Out:
		-NULL: entry is empty
		-A string containing the content of the standard input
*/
static char	*read_standard_empty_limiter(void)
{
	char	*entry_content;
	char	*tmp;
	char	*tmp2;

	ft_printf("\nheredoc> ");
	tmp = get_next_line(0);
	entry_content = ft_calloc(1, 1);
	if (!tmp || !entry_content)
		return (NULL);
	while (ft_strncmp(tmp, "\n", 1))
	{
		ft_printf("heredoc> ");
		tmp2 = ft_strdup(entry_content);
		free(entry_content);
		entry_content = ft_strjoin(tmp2, tmp);
		free(tmp2);
		free(tmp);
		tmp = get_next_line(0);
	}
	free(tmp);
	return (entry_content);
}

/* 
	Read Standard
	This function will read the entry on the standard entry
	If the limiter is empty, the function Read Standard Empty Limiter is called
	Will take the input on the standard entry until the "EOF" string is sent.
	In:
		-char *limiter: the string contaning the limiter for the here_doc
	Out:
		-NULL: entry is empty
		-A string containing the content of the standard input
*/
static char	*read_standard(char *limiter)
{
	char	*entry_content;
	char	*tmp;
	char	*tmp2;
	size_t	limiter_len;

	if (limiter[0] == '\0')
		return (read_standard_empty_limiter());
	limiter_len = ft_strlen(limiter);
	ft_printf("\nheredoc> ");
	tmp = get_next_line(0);
	entry_content = ft_calloc(1, 1);
	if (!tmp || !entry_content)
		return (NULL);
	while (ft_strncmp(tmp, limiter, limiter_len))
	{
		ft_printf("heredoc> ");
		tmp2 = ft_strdup(entry_content);
		free(entry_content);
		entry_content = ft_strjoin(tmp2, tmp);
		free(tmp2);
		free(tmp);
		tmp = get_next_line(0);
	}
	free(tmp);
	return (entry_content);
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
char	*read_entry(int entry, char **av)
{
	if (entry == 1)
		return (read_file(av[1]));
	else if (entry == 2)
		return (read_standard(av[2]));
	return (NULL);
}

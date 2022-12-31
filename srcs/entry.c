/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:18:27 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/31 17:42:52 by tgernez          ###   ########.fr       */
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
char	*read_file(char *file_name)
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

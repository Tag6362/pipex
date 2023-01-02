/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:02:58 by tgernez           #+#    #+#             */
/*   Updated: 2023/01/02 17:07:35 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	File Existence
	This function checks whether a file exists or not, creates the file if it 
	doesn't exist, and return the corresponding file descriptor, with the good 
	writing mode (>> if "here_doc", > else)
	Warning: Doesn't check if the opening went correctly
	Flags:
		-F_OK: check if file exist, 0 if exists
		-O_WRONLY: opens a file for writing only
		-O_APPEND: open the file and will append to the existing content the new
				   content
		-O_CREAT: if the file doesn't exists, creates a file with the given name
	In:
		-int entry:
			-1 if entry on file
			-2 if entry on here_doc (standard input)
		-char *filaname: a string containing the file of the file where the
						 output of the programme will be stored.
	Out: int
		-the file descriptor, with the correct writing method
*/
static int	file_existence(int entry, char *filename)
{
	if (entry == 1)
	{
		if (access(filename, F_OK) == 0)
			return (open(filename, O_WRONLY));
	}
	else
	{
		if (access(filename, F_OK) == 0)
			return (open(filename, O_APPEND | O_WRONLY));	
	}
	return (open(filename, O_CREAT | O_WRONLY));
}

/*
	Output To File
	This function takes the Output of the command line and puts it in a file
	with the correct writing mode, and closes the file
	In:
		-int entry
			-1 if entry on file
			-2 if entry on here_doc (standard input)
		-char *filaname: a string containing the file of the file where the
						 output of the programme will be stored.
	Out:
		-(-1) if filename OR output is/are NULL
		-1 if evertything went fine
*/
int ouput_to_file(int entry, char *filename, char *output)
{
	int	fd;

	if (!filename || !output)
		return (-1);
	fd = -1;
	while (fd == -1)
		fd = file_existence(entry, filename);
	ft_putstr_fd(output, fd);
	close(fd);
	return (1);
}
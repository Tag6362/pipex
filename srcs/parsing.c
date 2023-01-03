/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:37 by tgernez           #+#    #+#             */
/*   Updated: 2023/01/03 17:32:29 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
	Input Mode
	This function returns the input mode used for pipex
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
	Check Files
	This function checks if the filenames are correct, i.e not empty nor, for 
	the input file, not existing
	In:
		-char **av: arguments
	Out:
		-0 if error in the file name 
		-1 else
*/
static int	check_files(int ac, char **av)
{
	if (av[1][0] == '\0' || access(av[1], F_OK) != 0)
	{
		ft_printf("bash: %s: No such file or directory\n", av[1]);
		return (0);
	}
	if (av[ac - 1][0] == '\0')
	{
		ft_printf("bash: %s: No such file or directory\n", av[ac - 1]);
		return (0);
	}
	return (1);
}

/*
	Dependency of Check Commands
*/
static int	sub_check_commands(char **paths, char **command_full)
{
	int		i;
	int		exists;
	char	*command;

	i = 0;
	exists = -1;
	while (paths[i])
	{
		command = ft_strjoin(paths[i], command_full[0]);
		ft_printf("COMMAND %s /COMMAND\n", command);
		if (access(command, F_OK) == 0)
		{
			exists = i;
			free(command);
			break;
		}
		free(command);
		i++;
	}
	return (exists);
}


/*
	Check Commands
	This function will check whether or not the commands are valid.
	In:
		-int ac: arguments number
		-char **av: arguments
		-char **paths: paths to where the commands are supposed to be stored
	Out:
		-1 if all the commands are correct
		-0 else
*/
static int	check_commands(int ac, char **av, char **paths)
{
	int		i;
	char	**command_full;

	i = input_mode(av) + 1;
	while (i < ac - 1)
	{
		command_full = ft_split(av[i], ' ');
		if (command_full[0] == NULL)
			return (free(command_full), ft_printf("Command '' not found\n"), 0);
		if (sub_check_commands(paths, command_full) == -1)
			return (ft_printf("Command '%s' not found\n", command_full[0]),
				ft_free_strs(command_full), 0);
		ft_free_strs(command_full);
		i++;
	}
	return (1);
}

/*
	Is AV Correct ?
	This function will check if:
		-the file names (in and out) are empty
		-the commands are empty (no matter their position in the pipe line)
	In:
		-int ac: arguments number
		-char **av: arguments
		-char **paths: the paths where the bash commands' files might me stored
	Out: int
		-0 if problem
		-1 if correct
*/
int	is_av_correct(int ac, char **av, char **paths)
{
	if (check_files(ac, av) && check_commands(ac, av, paths))
		return (1);
	return (0);
}

/*
	Find Paths
	This function will return a list of strings containing the different folders
	with the bash command scripts, and adds a '/' at the end for easier use
	In:
		-char **envp: Environment Pointer
	Out: char **
		-NULL: nothing / error occured
		-A table containing each path, with an extra '/' at the end
*/
char	**find_paths(char **envp)
{
	int		i;
	char	**paths;
	char	*tmp;

	i = 0;
	while (envp[i] && !ft_strstr(envp[i], "PATH"))
		i++;
	if (envp[i] == NULL)
		return (NULL);
	while (*(envp[i]) && '=' != *(envp[i]))
		(envp[i])++;
	paths = ft_split(envp[i] + 1, ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = ft_strdup(tmp);
		free(tmp);
		i++;		
	}	
	return (paths);
}

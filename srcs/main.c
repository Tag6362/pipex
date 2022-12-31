/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:30:16 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/31 17:38:39 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Get Working Directory
In: Char **envp, environment
Out: Char *, NOT mallocated	-if founds the Working Directory, returns the absolute path to it
			-if not found, returns NULL
*/
// static char	*ft_gwd(char **envp)
// {
// 	int		i;
// 	char	*tmp;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		tmp = ft_strstr(envp[i], "PWD");
// 		if (tmp)
// 			return (tmp + 4);
// 		free(tmp);
// 		i++;
// 	}
// 	return ("");
// }
char	*princ(int ac, char **av, char **envp)
{
	char	*res;
	int		entry;
	char	**paths;
	char	*content;

	if (ac < 5 || !av)
		return("Wrong argument number!\n");
	if (!envp || !(*envp))
		return ("Problem in environment!\n");
	if (!is_av_correct(ac, av))
		return ("Problem in arguments!\n");
	entry = input_mode(av);
	paths = find_paths(envp);
	content = read_file(av[1]);
	ft_printf("%s\n", content);
	if (paths)
		ft_free_strs(paths);
	if (content)
		free(content);
	res = NULL; // SILENCER
	return (res);
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	test_6();
	test_7();
	test_8();
	test_9();
	test_10();
	test_11();
	test_12();

	return (0);
}

// char	*princ(int ac, char **av, char **envp)
// {
// 	(void)ac;
// 	(void)av;
// 	(void)envp;
// 	return ("");
// }

// int main(int ac, char **av, char **envp)
// {
// 	(void) ac;
// 	(void) av;
// 	(void) envp;
// 	int		exec_state;
// 	// char	*wd;
// 	char	*file;
// 	pid_t	fork_pid;

// 	// wd =  ft_gwd(envp);
// 	// ft_printf("%s\n", wd);
// 	file = ft_strjoin(".", "/hello.sh");
// 	fork_pid = fork();
// 	if (fork_pid == -1)
// 		return (-1);
// 	exec_state = 0;
// 	if (fork_pid == 0)
// 	{
// 		exec_state = execve(file, NULL, NULL);
// 		if (exec_state == -1)
// 			exit(1);
// 		exit(0);
// 	}
// 	else
// 	{
// 		ft_printf("Printed %d\n", fork_pid);
// 		wait(NULL);
// 		exit(0);
// 	}
// 	test_1();
// 	test_2();
// 	test_3();
// 	test_4();
// 	free(file);
// 	return (0);
// }

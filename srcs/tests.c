/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:14:34 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/29 15:39:1 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int test_1(void)
{
	int		ac;
	char	**av;
	char	**envp;
	int		val;

	ft_printf("Basic Test 1: Empty environment...");
	ac = 6;

	av = malloc(sizeof(char *) * 6);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("infile");
	av[2] = ft_strdup("ls -l");
	av[3] = ft_strdup("wc -l");
	av[4] = ft_strdup("outfile");
	av[5] = NULL;

	envp = NULL;

	val = ft_strncmp(princ(ac, av, envp), "Problem in environment!\n", 1000);
	ft_free_strs(av);
	ft_free_strs(envp);
	if (val == 0)
		return(ft_printf("success!\n"), 1);
	return (ft_printf("failure!\n"), 0);
}

int test_2(void)
{
	int		ac;
	char	**av;
	char	**envp;
	int		val;

	ft_printf("Basic Test 2: No argument...");
	ac = 1;

	av = malloc(sizeof(char *) * 2);
	av[0] = ft_strdup("pipex");
	av[1] = NULL;

	envp = malloc(sizeof(char *) * 2);
	envp[0] = ft_strdup("PWD:/Users/tgernez/Documents/C/42/tgernez/pipex");
	envp[1] = NULL;

	val = ft_strncmp(princ(ac, av, envp), "Wrong argument number!\n", 1000);
	ft_free_strs(av);
	ft_free_strs(envp);
	if (val == 0)
		return(ft_printf("success!\n"), 1);
	return (ft_printf("failure!\n"), 0);
}

int test_3(void)
{
	int		ac;
	char	**av;
	char	**envp;
	int		val;

	ft_printf("Basic Test 3: Wrong argument number...");
	ac = 5;

	av = malloc(sizeof(char *) * 5);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("infile");
	av[2] = ft_strdup("ls -l");
	av[3] = ft_strdup("wc -l");
	av[4] = NULL;

	envp = malloc(sizeof(char *) * 2);
	envp[0] = ft_strdup("PWD:/Users/tgernez/Documents/C/42/tgernez/pipex");
	envp[1] = NULL;

	val = ft_strncmp(princ(ac, av, envp), "Wrong argument number!\n", 1000);
	ft_free_strs(av);
	ft_free_strs(envp);
	if (val == 0)
		return(ft_printf("success!\n"), 1);
	return (ft_printf("failure!\n"), 0);
}

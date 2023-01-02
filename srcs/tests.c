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

	ft_printf("Basic Test 1 : Empty environment...");
	ac = 5;

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
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_2(void)
{
	int		ac;
	char	**av;
	char	**envp;
	int		val;

	ft_printf("Basic Test 2 : No argument...");
	ac = 1;

	av = malloc(sizeof(char *) * 2);
	av[0] = ft_strdup("pipex");
	av[1] = NULL;

	envp = malloc(sizeof(char *) * 2);
	envp[0] = ft_strdup("PATH=/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	envp[1] = NULL;

	val = ft_strncmp(princ(ac, av, envp), "Wrong argument number!\n", 1000);
	ft_free_strs(av);
	ft_free_strs(envp);
	if (val == 0)
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_3(void)
{
	int		ac;
	char	**av;
	char	**envp;
	int		val;

	ft_printf("Basic Test 3 : Wrong argument number...");
	ac = 4;

	av = malloc(sizeof(char *) * 5);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("infile");
	av[2] = ft_strdup("ls -l");
	av[3] = ft_strdup("wc -l");
	av[4] = NULL;

	envp = malloc(sizeof(char *) * 2);
	envp[0] = ft_strdup("PATH=/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	envp[1] = NULL;

	val = ft_strncmp(princ(ac, av, envp), "Wrong argument number!\n", 1000);
	ft_free_strs(av);
	ft_free_strs(envp);
	if (val == 0)
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_4(void)
{
	char	**av;
	int		val;

	ft_printf("Basic Test 4 : Testing here_doc detection...");

	av = malloc(sizeof(char *) * 7);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("here_doc");
	av[2] = ft_strdup("EOF");
	av[3] = ft_strdup("ls -l");
	av[4] = ft_strdup("wc -l");
	av[5] = ft_strdup("outfile");
	av[6] = NULL;

	val = input_mode(av) == 2;
	ft_free_strs(av);
	if (val == 1)
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_5(void)
{
	char	**av;
	int		val;

	ft_printf("Basic Test 5 : Testing file name starting by here_doc...");

	av = malloc(sizeof(char *) * 6);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("here_docoi");
	av[2] = ft_strdup("ls -l");
	av[3] = ft_strdup("wc -l");
	av[4] = ft_strdup("outfile");
	av[5] = NULL;

	val = input_mode(av) == 1;
	ft_free_strs(av);
	if (val == 1)
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_6(void)
{
	int		ac;
	char	**av;
	char	**envp;
	int		val;

	ft_printf("Basic Test 6 : Empty string infile...");
	ac = 5;

	av = malloc(sizeof(char *) * 6);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("");
	av[2] = ft_strdup("ls -l");
	av[3] = ft_strdup("wc -l");
	av[4] = ft_strdup("outfile");
	av[5] = NULL;

	envp = malloc(sizeof(char *) * 2);
	envp[0] = ft_strdup("PATH=/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	envp[1] = NULL;

	val = ft_strncmp(princ(ac, av, envp), "Problem in arguments!\n", 10000);
	ft_free_strs(av);
	ft_free_strs(envp);
	if (val == 0)
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_7(void)
{
	int		ac;
	char	**av;
	char	**envp;
	int		val;

	ft_printf("Basic Test 7 : Empty string outfile...");
	ac = 5;

	av = malloc(sizeof(char *) * 6);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("infile");
	av[2] = ft_strdup("ls -l");
	av[3] = ft_strdup("wc -l");
	av[4] = ft_strdup("");
	av[5] = NULL;

	envp = malloc(sizeof(char *) * 2);
	envp[0] = ft_strdup("PATH=/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	envp[1] = NULL;

	val = ft_strncmp(princ(ac,av, envp), "Problem in arguments!\n", 10000);
	ft_free_strs(av);
	ft_free_strs(envp);
	if (val == 0)
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_8(void)
{
	int		ac;
	char	**av;
	char	**envp;
	int		val;

	ft_printf("Basic Test 8 : Empty string infile and outfile...");
	ac = 5;

	av = malloc(sizeof(char *) * 6);
	av[0] = ft_strdup("");
	av[1] = ft_strdup("infile");
	av[2] = ft_strdup("ls -l");
	av[3] = ft_strdup("wc -l");
	av[4] = ft_strdup("");
	av[5] = NULL;

	envp = malloc(sizeof(char *) * 2);
	envp[0] = ft_strdup("PATH=/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	envp[1] = NULL;

	val = ft_strncmp(princ(ac,av, envp), "Problem in arguments!\n", 10000);
	ft_free_strs(av);
	ft_free_strs(envp);
	if (val == 0)
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_9(void)
{
	int		ac;
	char	**av;
	char	**envp;
	int		val;

	ft_printf("Basic Test 9 : Empty string first command...");
	ac = 5;

	av = malloc(sizeof(char *) * 6);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("infile");
	av[2] = ft_strdup("");
	av[3] = ft_strdup("wc -l");
	av[4] = ft_strdup("outfile");
	av[5] = NULL;

	envp = malloc(sizeof(char *) * 2);
	envp[0] = ft_strdup("PATH=/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	envp[1] = NULL;

	val = ft_strncmp(princ(ac,av, envp), "Problem in arguments!\n", 10000);
	ft_free_strs(av);
	ft_free_strs(envp);
	if (val == 0)
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_10(void)
{
	int		ac;
	char	**av;
	char	**envp;
	int		val;

	ft_printf("Basic Test 10: Empty string random command...");
	ac = 6;

	av = malloc(sizeof(char *) * 7);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("infile");
	av[2] = ft_strdup("ls -l");
	av[3] = ft_strdup("");
	av[4] = ft_strdup("wc -l");
	av[5] = ft_strdup("outfile");
	av[6] = NULL;

	envp = malloc(sizeof(char *) * 2);
	envp[0] = ft_strdup("PATH=/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	envp[1] = NULL;

	val = ft_strncmp(princ(ac,av, envp), "Problem in arguments!\n", 10000);
	ft_free_strs(av);
	ft_free_strs(envp);
	if (val == 0)
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_11(void)
{
	int		ac;
	char	**av;
	char	**envp;
	int		val;

	ft_printf("Basic Test 11: Empty string last command...");
	ac = 6;

	av = malloc(sizeof(char *) * 7);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("infile");
	av[2] = ft_strdup("ls -l");
	av[3] = ft_strdup("wc -l");
	av[4] = ft_strdup("");
	av[5] = ft_strdup("outfile");
	av[6] = NULL;

	envp = malloc(sizeof(char *) * 2);
	envp[0] = ft_strdup("PATH=/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/mnt/nfs/homes/tgernez/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	envp[1] = NULL;

	val = ft_strncmp(princ(ac,av, envp), "Problem in arguments!\n", 10000);
	ft_free_strs(av);
	ft_free_strs(envp);
	if (val == 0)
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_12(void)
{
	int		ac;
	char	**av;
	char	*content;
	int		val;

	ft_printf("Basic Test 12: reading an empty file...");
	ac = 5;

	av = malloc(sizeof(char *) * 7);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("emptyfile");
	av[2] = ft_strdup("ls -l");
	av[3] = ft_strdup("wc -l");
	av[4] = ft_strdup("outfile");
	av[5] = NULL;

	content = read_entry(1, av);
	val = ft_strncmp(content, "", 10000) == 0;
	ft_free_strs(av);
	if (val == 1)
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_13(void)
{
	char	**av;
	char	*content;
	int		val;

	ft_printf("Basic Test 13: Testing here_doc empty...");

	av = malloc(sizeof(char *) * 7);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("here_doc");
	av[2] = ft_strdup("EOF");
	av[3] = ft_strdup("ls -l");
	av[4] = ft_strdup("wc -l");
	av[5] = ft_strdup("outfile");
	av[6] = NULL;

	ft_printf("\033[1;33mSEMI-AUTO TEST: please type 'EOF' and hit 'Return'\033[0m!");
	content = read_entry(2, av);
	val = (ft_strncmp(content, "", 10000) == 0);
	free(content);
	ft_free_strs(av);
	if (val == 1)
		return(ft_printf("\033[1;32msuccess\033[0m!\n"), 1);
	return (ft_printf("\033[1;31mfailure\033[0m!\n"), 0);
}

int test_14(void)
{
	char	**av;
	char	*content;

	ft_printf("Basic Test 13: Testing here_doc content...");

	av = malloc(sizeof(char *) * 7);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("here_doc");
	av[2] = ft_strdup("EOF");
	av[3] = ft_strdup("ls -l");
	av[4] = ft_strdup("wc -l");
	av[5] = ft_strdup("outfile");
	av[6] = NULL;

	ft_printf("\033[1;35mMANUAL TEST: please type what you want, then type 'EOF' and hit 'Return', check if it matches what you typed\033[0m!");
	content = read_entry(2, av);
	ft_printf("\033[1;34m%s\033[0m", content);
	free(content);
	ft_free_strs(av);
	return (0);
}

int test_15(void)
{
	char	**av;
	char	*content;

	ft_printf("Basic Test 13: Testing here_doc empty string limiter...");

	av = malloc(sizeof(char *) * 7);
	av[0] = ft_strdup("pipex");
	av[1] = ft_strdup("here_doc");
	av[2] = ft_strdup("");
	av[3] = ft_strdup("ls -l");
	av[4] = ft_strdup("wc -l");
	av[5] = ft_strdup("outfile");
	av[6] = NULL;

	ft_printf("\033[1;35mMANUAL TEST: please type what you want, then hit 'Return' twice, check if it matches what you typed\033[0m!");
	content = read_entry(2, av);
	ft_printf("\033[1;34m%s\033[0m", content);
	free(content);
	ft_free_strs(av);
	return (0);
}


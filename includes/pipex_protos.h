/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_protos.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:05:37 by tgernez           #+#    #+#             */
/*   Updated: 2023/01/01 17:51:08 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PROTOS_H
# define PIPEX_PROTOS_H


/* Main */
char	*princ(int ac, char **av, char **envp);

/* Parsing */
int		input_mode(char **av);
int		is_av_correct(int ac, char **av);
char	**find_paths(char **envp);

/* Entry */
char *read_entry(int entry, char **av);

/* Tests */
int		test_1(void);
int		test_2(void);
int		test_3(void);
int		test_4(void);
int		test_5(void);
int		test_6(void);
int		test_7(void);
int		test_8(void);
int		test_9(void);
int		test_10(void);
int		test_11(void);
int		test_12(void);
int		test_13(void);
int		test_14(void);
int		test_15(void);

#endif

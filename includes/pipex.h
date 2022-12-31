/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:53:02 by tgernez           #+#    #+#             */
/*   Updated: 2022/12/29 16:04:05 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "pipex_protos.h"
# include "pipex_structs.h"

/* Main */
char *princ(int ac, char **av, char **envp);

/* Tests */
int	test_1(void);
int	test_2(void);
int	test_3(void);


#endif

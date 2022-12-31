# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 17:41:24 by tgernez           #+#    #+#              #
#    Updated: 2022/12/31 17:20:36 by tgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
FTSRCS			= .c
DIRSRCS 		= srcs/
SRCS 			=	$(addsuffix ${FTSRCS},	\
					$(addprefix ${DIRSRCS},	\
					main \
					entry \
					parsing \
					tests \
					))
INCLUDES		= -Iincludes
LIBFTDIR		= libft
LIBFTLIB		= -lft
CC				= clang
FLAGS			= -Wall -Wextra -Werror
OBJS			= ${SRCS:.c=.o}
RM				= rm -rf
RED				= \033[1;31m
NC				= \033[0m
LGREEN			= \033[1;32m
CYAN			= \033[1;36m

%.o: %.c
	@echo "\033[1A                                                          "
	@echo -n "\033[1A"
	@echo "${CYAN}Compiling $< ${NC}"
	@${CC} ${FLAGS} -o $@ -c $^ ${INCLUDES}

all: ${NAME}
	@echo ''
	@echo 'PPPPPPPPPPPPPPPPP      iiii'
	@echo 'P::::::::::::::::P    i::::i'
	@echo 'P::::::PPPPPP:::::P    iiii'
	@echo 'PP:::::P     P:::::P'
	@echo '  P::::P     P:::::P iiiiiiii ppppp   ppppppppp        eeeeeeeeeeee   xxxxxxx      xxxxxxx'
	@echo '  P::::P     P:::::P i::::::i p::::ppp:::::::::p     ee::::::::::::ee  x:::::x    x:::::x'
	@echo '  P::::PPPPPP:::::P   i::::i  p:::::::::::::::::p   e::::::eeeee:::::ee x:::::x  x:::::x'
	@echo '  P:::::::::::::PP    i::::i  pp::::::ppppp::::::p e::::::e     e:::::e  x:::::xx:::::x'
	@echo '  P:::PPPPPPPPP       i::::i   p:::::p     p:::::p e:::::::eeeee::::::e   x::::::::::x'
	@echo '  P::::P              i::::i   p:::::p     p:::::p e:::::::::::::::::e     x::::::::x'
	@echo '  P::::P              i::::i   p:::::p     p:::::p e::::::eeeeeeeeeee      x::::::::x'
	@echo '  P::::P              i::::i   p:::::p    p::::::p e:::::::e              x::::::::::x'
	@echo 'PP::::::PP           i::::::i  p:::::ppppp:::::::p e::::::::e            x:::::xx:::::x'
	@echo 'P::::::::P           i::::::i  p::::::::::::::::p   e::::::::eeeeeeee   x:::::x  x:::::x'
	@echo 'P::::::::P           i::::::i  p::::::::::::::pp     ee:::::::::::::e  x:::::x    x:::::x'
	@echo 'PPPPPPPPPP           iiiiiiii  p::::::pppppppp         eeeeeeeeeeeeee xxxxxxx      xxxxxxx'
	@echo '                               p:::::p'
	@echo '                               p:::::p'
	@echo '                              p:::::::p'
	@echo '                              p:::::::p'
	@echo '                              p:::::::p'
	@echo '                              ppppppppp'
	@echo '                                                                                by tgernez'
	@echo "${LGREEN}Successfully created${NC}${CYAN} ${NAME}${NC}${LGREEN}!${NC}"

${NAME}: ${OBJS} ${LIBFTDIR}/libft.a
	@${CC} ${OBJS} ${INCLUDES} -L${LIBFTDIR} ${LIBFTLIB} -o $@

sanitize: ${OBJS} ${LIBFTDIR}/libft.a
	@${CC} ${OBJS} ${INCLUDES} -L${LIBFTDIR} ${LIBFTLIB} -o pipex -g3 -fsanitize=address

${LIBFTDIR}/libft.a:
	@make -C ${LIBFTDIR}

safe:
	git add .
	git commit -m "AUTOSAFEGARD"
	git push

#----------------------------PIPEX

clean:
	@echo "${CYAN}Cleaned ${NAME}${NC}"
	@${RM} ${OBJS}

fclean:		clean
	@echo "${CYAN}FCleaned ${NAME}${NC}"
	@${RM} ${NAME}

re: fclean all

#----------------------------LIBFT

libft_all:
	@make -C ${LIBFTDIR} all

libft_clean:
	@make -C ${LIBFTDIR} clean

libft_fclean:
	@make -C ${LIBFTDIR} fclean


libft_re:
	@make -C ${LIBFTDIR} re

#----------------------------ALL

all_clean: clean libft_clean

all_fclean: fclean libft_fclean

all_re: libft_re fclean all
	@echo "${CYAN}Re-ed ${NAME}${NC}"

re: fclean all

.PHONY: all clean fclean re libft_re libft_all libft_fclean libft_clean all_clean all_fclean

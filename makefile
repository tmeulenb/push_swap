#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmeulenb <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/06 20:59:41 by tmeulenb      #+#    #+#                  #
#    Updated: 2019/05/06 20:59:41 by tmeulenb      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = pushswap
SRCSPW = push_swap.c easy_algo.c sort_a.c sort_b.c sort_help.c sort_help1.c \
		extra.c	input.c initialize.c operations.c operations_help.c flags.c \
		make_sorted_stack.c
OBJPW = push_swap.o easy_algo.o sort_a.o sort_b.o sort_help.o sort_help1.o \
		extra.o input.o initialize.o operations.o operations_help.o flags.o \
		make_sorted_stack.o
SRCSCH = checker.c extra.c input.c initialize.c operations.c operations_help.c \
flags.c sort_help1.c sort_help.c make_sorted_stack.c
OBJCH =  checker.o extra.o input.o initialize.o operations.o operations_help.o \
flags.o sort_help1.o sort_help.o make_sorted_stack.o
FLAGS = -Wall -Werror -Wextra -o
GCC = gcc
GNL = ./gnl/get_next_line.c
LIBS = ./libft/libft.a

all:
	@make push_swap
	@make checker

push_swap:
	@make -C libft/ > /dev/null
	@$(GCC) -g $(SRCSPW) $(GNL) $(FLAGS) push_swap $(LIBS) > /dev/null
	@echo "\033[32mPUSHSWAP READY\033[0m"

checker:
	@make -C libft/ > /dev/null
	@$(GCC) -g $(SRCSCH) $(GNL) $(FLAGS) checker $(LIBS) > /dev/null
	@echo "\033[32mCHECKER READY\033[0m"

clean:
	@rm -rf $(OBJPW) $(OBJCH) > /dev/null
	@make clean -C libft/ > /dev/null
	@echo "\033[33mOBJ FILES REMOVED\033[0m"

fclean: clean
	@rm -rf checker push_swap > /dev/null 
	@make fclean -C libft/ > /dev/null
	@echo "\033[31mBINARIES REMOVED\033[0m"

re: fclean all
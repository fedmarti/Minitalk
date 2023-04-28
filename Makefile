#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := server
NAME_C		:= client
LIBFT		:= libft.a
FT_PRINTF	:= libftprintf.a
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      server.c \
					list_logic.c

SRCS_C		:=		client.c \
                          
OBJS        := $(SRCS:.c=.o)

OBJS_C      := $(SRCS_C:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${NAME_C} ${LIBFT} ${FT_PRINTF} ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS} libft/${LIBFT} ft_printf/${FT_PRINTF}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

${NAME_C}:	${OBJS_C} ${LIBFT} ${FT_PRINTF}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME_C} ${OBJS_C} libft/${LIBFT} ft_printf/${FT_PRINTF}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

${LIBFT}:
			@make -C ./libft
			@echo "$(GREEN)$(LIBFT) created[0m ✔️"

${FT_PRINTF}:
			@make -C ./ft_printf
			@echo "$(GREEN)$(FT_PRINTF) created[0m ✔️"

all:		${NAME} ${NAME_C}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re



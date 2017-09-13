##
## Makefile for <LIST> in /home/barrau_a//c/list
## 
## Made by adrien barrau
## Login   <barrau_a@epitech.net>
## 
## Started on  Tue Apr 19 14:54:34 2011 adrien barrau
## Last update Thu Jun 23 21:10:30 2011 adrien barrau
##

LIB_NAME	=	liblist.a

SRCS		=	access_list.c		\
			capacity_list.c		\
			misc_list.c		\
			pop_list.c		\
			list_clear.c		\
			pop_nofree_list.c	\
			list_clear_nofree.c	\
			push_list.c

OBJS		=	$(SRCS:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS		+=	-W -Wall -Wextra -Werror

LDFLAGS		+=

AR		=	ar rcs

all		:	$(LIB_NAME)

$(LIB_NAME)	:	$(OBJS)
			$(AR) $(LIB_NAME) $(OBJS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(LIB_NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
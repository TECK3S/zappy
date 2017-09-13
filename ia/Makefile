NAME		= client_ia

SRCS		= Observable.cpp \
                  iaclientsingleton.cpp \
                  ClientIA.cpp \
                  main.cpp


LDFLAGS		= -L/usr/local/lib -llua


OBJS		= $(SRCS:.cpp=.o)
CC		= g++
CXXFLAGS	+= $(LDFLAGS) -W -Wall -O3
RM		= rm -f
ECHO		= echo -e

all		: $(NAME)

$(NAME)      	: $(OBJS)
		@$(CC)  $(CXXFLAGS) -o $(NAME) $(OBJS) $(LIB)
		@$(ECHO) '\033[0;32m> Compiled\033[0m'

clean		:
		@$(RM) $(OBJS)
		@$(RM) *~
		@$(RM) #*#
		@$(ECHO) '\033[0;35m> Directory cleaned\033[0m'

fclean		: clean
		@$(RM) $(NAME)
		@$(ECHO) '\033[0;35m> Remove executable\033[0m'

re		: fclean all

.PHONY		: all clean re


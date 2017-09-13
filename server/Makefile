##
## Makefile for <Zappy> in /home/barrau_a//c/zappy_delamort/server
## 
## Made by adrien barrau
## Login   <barrau_a@epitech.net>
## 
## Started on  Wed Jun  1 10:12:56 2011 adrien barrau
## Last update Sun Jul 10 22:55:32 2011 rahman-serdar aysan
##

NAME		=	zappy

SRCS		=	main.c			\
			parse_args.c		\
			parse_playing_cmd.c	\
			parse_connected_cmd.c	\
			parse_graphic_cmd.c	\
			action_connected.c	\
			action_playing.c	\
			action_graphic.c	\
			zappy_server.c		\
			socket.c		\
			my_accept.c		\
			zap_manager.c		\
			get_command.c		\
			get_client.c		\
			fill_buffer.c		\
			flush_buffer.c		\
			act_playing.c		\
			act_graphic.c		\
			act_fork.c		\
			find_team.c		\
			act_avance.c		\
			act_droite.c		\
			act_gauche.c		\
			act_inventaire.c	\
			act_prend.c		\
			act_pose.c		\
			act_expulse.c		\
			act_incantation.c	\
			get_sound.c		\
			act_broadcast.c		\
			act_connect_nbr.c	\
			generate.c		\
			action_cmd.c		\
			action_cmd_suite.c	\
			cmd_protocol.c		\
			cmd_protocol_suite.c	\
			redistribute_res.c	\
			cmd_response.c		\
			cmd_response_suite.c	\
			act_connected.c		\
			act_bct.c		\
			act_ebo.c		\
			act_edi.c		\
			act_eht.c		\
			act_enw.c		\
			act_mct.c		\
			act_msz.c		\
			act_pbc.c		\
			act_pdi.c		\
			act_pdr.c		\
			act_pex.c		\
			act_pfk.c		\
			act_pgt.c		\
			act_pic.c		\
			act_pie.c		\
			act_pin.c		\
			act_plv.c		\
			act_pnw.c		\
			act_ppo.c		\
			act_sbp.c		\
			act_seg.c		\
			act_sgt.c		\
			act_smg.c		\
			act_sst.c		\
			act_tna.c		\
			get_client_dir.c	\
			response_to_str.c	\
			timize_actions.c	\
			win_condition.c		\
			init_trantor.c		\
			init_sigaction.c	\
			egg.c			\
			purge_client.c		\
			free_all.c		\
			redistribute_ressource.c

OBJS		=	$(SRCS:.c=.o)
OBJP		=	$(addprefix $(OBJS_PATH), $(OBJS))

INCLUDE_PATH	=	includes/
OBJS_PATH	=	objs/
SRCS_PATH	=	src/
LIB_PATH	=	lib/

LIST_NAME	=	list

CFLAGS		+=	-W -Wall -Wextra -Werror -I$(INCLUDE_PATH)
LDFLAGS		=	-L$(LIB_PATH) -l$(LIST_NAME)

CC		=	gcc
RM		=	/bin/rm -f

vpath		%.c	$(SRCS_PATH)

all		:	$(NAME)

%.o		:	%.c
			$(CC) -c $(CFLAGS) $< -o $(addprefix $(OBJS_PATH), $@)

$(NAME)		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJP) $(LDFLAGS)

clean		:
			$(RM) $(OBJP)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re

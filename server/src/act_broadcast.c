/*
** act_broadcast.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 21:21:25 2011 rahman-serdar aysan
** Last update Sun Jul 10 21:30:29 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

static inline void	send_to(content_t * cont, param_t p)
{
  pack_msg *	pack = (pack_msg *)p;
  client **	cli = (client **)cont;
  t_float_pos	sender, receiver;

  if ((*cli)->state == PLAYING
      && (*cli)->socket != pack->cli->socket)
    {
      sender.x = pack->cli->pos.x + 0.5;
      sender.y = pack->cli->pos.y + 0.5;
      receiver.x = (*cli)->pos.x + 0.5;
      receiver.y = (*cli)->pos.y + 0.5;
      answer(response_message(pack->msg,
			      get_sound(&sender, &receiver, (*cli)->dir)), *cli);
    }
}

void		act_broadcast(action_param param,
			      client * cli,
			      zappy * zap)
{
  pack_msg	pack;

  answer(response_ok(), cli);
  pack.cli = cli;
  pack.msg = (char *)param;
  list_iter(&zap->client_list, &pack, &send_to);
}

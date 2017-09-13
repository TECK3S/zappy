/*
** act_avance.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 20:46:54 2011 rahman-serdar aysan
** Last update Sun Jul 10 22:45:31 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		update_pos(int * pos, int off, int max)
{
  *pos += off;
  if (*pos < 0)
    *pos = max;
  if (*pos > max)
    *pos = 0;
}

void		act_avance(action_param param __attribute__((unused)),
			   client * cli,
			   zappy * zap)
{
  zap->trantor[(cli->pos.y * zap->trantor_width)
	       + cli->pos.x].obj[PLAYER] -= 1;
  switch (cli->dir)
    {
    case UP:    update_pos(&cli->pos.y, -1, zap->trantor_height - 1); break;
    case RIGHT: update_pos(&cli->pos.x,  1, zap->trantor_width  - 1); break;
    case DOWN:  update_pos(&cli->pos.y,  1, zap->trantor_height - 1); break;
    case LEFT:  update_pos(&cli->pos.x, -1, zap->trantor_width  - 1); break;
    default:							      break;
    }
  zap->trantor[(cli->pos.y * zap->trantor_width)
	       + cli->pos.x].obj[PLAYER] += 1;
  answer(response_ok(), cli);
}

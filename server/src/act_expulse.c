/*
** act_expulse.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 20:58:16 2011 rahman-serdar aysan
** Last update Sun Jul 10 20:59:13 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

static inline int	get_where(t_pos * pos, client * cli)
{
  int		where = 0;

  if (pos[0].x > pos[1].x)
    where = 7;
  else if (pos[0].x < pos[1].x)
    where = 3;
  else if (pos[0].y > pos[1].y)
    where = 5;
  else if (pos[0].y < pos[1].y)
    where = 1;
  where = (((where - 1) + (2 * cli->dir)) % 8) + 1;
  return (where);
}

static inline void	expulse_player(t_pos * pos, zappy * zap, int expulsor)
{
  t_node *	cur = zap->client_list;
  client *	cli = NULL;

  while (cur != NULL)
    {
      cli = (client *)cur->cont;
      if (cli->socket != expulsor && cli->pos.x
	  == pos[0].x && cli->pos.y == pos[0].y)
	{
	  answer(response_deplacement(get_where(pos, cli)), cli);
	  zap->trantor[(cli->pos.y * zap->trantor_width)
		       + cli->pos.x].obj[PLAYER] -= 1;
	  cli->pos.x = pos[1].x;
	  cli->pos.y = pos[1].y;
	  zap->trantor[(cli->pos.y * zap->trantor_width)
		       + cli->pos.x].obj[PLAYER] += 1;
	}
      cur = cur->next;
    }
}

void		act_expulse(action_param param __attribute__((unused)),
			    client * cli,
			    zappy * zap)
{
  t_pos		pos[2];

  if (zap->trantor[(cli->pos.y * zap->trantor_width)
		   + cli->pos.x].obj[PLAYER] > 1)
    {
      pos[0].x = cli->pos.x;
      pos[0].y = cli->pos.y;
      pos[1].x = cli->pos.x;
      pos[1].y = cli->pos.y;
      switch (cli->dir)
	{
	case UP:    update_pos(&pos[1].y, -1, zap->trantor_height - 1); break;
	case RIGHT: update_pos(&pos[1].x,  1, zap->trantor_width  - 1); break;
	case DOWN:  update_pos(&pos[1].y,  1, zap->trantor_height - 1); break;
	case LEFT:  update_pos(&pos[1].x, -1, zap->trantor_width  - 1); break;
	default:							break;
	}
      expulse_player(pos, zap, cli->socket);
      answer(response_ok(), cli);
    }
  else
    answer(response_ko(), cli);
}

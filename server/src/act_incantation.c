/*
** act_incantation.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 21:05:58 2011 rahman-serdar aysan
** Last update Sun Jul 10 21:12:31 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

static level_up	lvl_up[]=
  {
/*             player, linemate, deraumere, sibur, mendiane, phiras, thystame */
/* unused */ {   9   ,    9    ,     9    ,   9  ,    9    ,   9   ,    9    },
/* 1 -> 2 */ {   1   ,    1    ,     0    ,   0  ,    0    ,   0   ,    0    },
/* 2 -> 3 */ {   2   ,    1    ,     1    ,   1  ,    0    ,   0   ,    0    },
/* 3 -> 4 */ {   2   ,    2    ,     0    ,   1  ,    0    ,   2   ,    0    },
/* 4 -> 5 */ {   4   ,    1    ,     1    ,   2  ,    0    ,   1   ,    0    },
/* 5 -> 6 */ {   4   ,    1    ,     2    ,   1  ,    3    ,   0   ,    0    },
/* 6 -> 7 */ {   6   ,    1    ,     2    ,   3  ,    0    ,   1   ,    0    },
/* 7 -> 8 */ {   6   ,    2    ,     2    ,   2  ,    2    ,   2   ,    1    }
  };

static inline void	check_level(content_t * cont, param_t param)
{
  client *	cli = (client *)*cont;
  lvl_checker *	ck = (lvl_checker *)param;

  if (cli->state == PLAYING
      && ck->cli->pos.x == cli->pos.x
      && ck->cli->pos.y == cli->pos.y
      && ck->cli->level == cli->level)
    ck->checker++;
}

static inline void	response_level(content_t * cont, param_t param)
{
  client *	cli = (client *)*cont;
  client *	ref_cli = (client *)param;

  if (cli->state == PLAYING
      && ref_cli->socket != cli->socket
      && ref_cli->pos.x == cli->pos.x
      && ref_cli->pos.y == cli->pos.y
      && ref_cli->level == cli->level)
    {
      cli->level += 1;
      answer(response_elevation(cli->level), cli);
    }
}

static inline void	send_response(zappy * zap, client * cli, objects * box)
{
  answer(response_ok(), cli);
  cli->level += 1;
  list_iter(&zap->client_list, cli, &response_level);
  box->obj[LINEMATE] = 0;
  box->obj[DERAUMERE] = 0;
  box->obj[SIBUR] = 0;
  box->obj[MENDIANE] = 0;
  box->obj[PHIRAS] = 0;
  box->obj[THYSTAME] = 0;
}

void		act_incantation(action_param param __attribute__((unused)),
				client * cli, zappy * zap)
{
  objects *	box = &zap->trantor[(cli->pos.y
				     * zap->trantor_width) + cli->pos.x];
  lvl_checker	check;

  if (cli->level > 0 && cli->level < 8
      && box->obj[PLAYER]    == lvl_up[cli->level].player
      && box->obj[LINEMATE]  == lvl_up[cli->level].linemate
      && box->obj[DERAUMERE] == lvl_up[cli->level].deraumere
      && box->obj[SIBUR]     == lvl_up[cli->level].sibur
      && box->obj[MENDIANE]  == lvl_up[cli->level].mendiane
      && box->obj[PHIRAS]    == lvl_up[cli->level].phiras
      && box->obj[THYSTAME]  == lvl_up[cli->level].thystame)
    {
      check.cli = cli;
      check.checker = 0;
      list_iter(&zap->client_list, &check, &check_level);
      if (check.checker == lvl_up[cli->level].player)
	send_response(zap, cli, box);
      else
	answer(response_ko(), cli);
    }
  else
    answer(response_ko(), cli);
}

/*
** act_prend.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 20:54:37 2011 rahman-serdar aysan
** Last update Sun Jul 10 20:55:19 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_prend(action_param param, client * cli, zappy * zap)
{
  if (zap->trantor[(cli->pos.y * zap->trantor_width)
		   + cli->pos.x].obj[(int)param] > 0)
    {
      zap->trantor[(cli->pos.y * zap->trantor_width)
		   + cli->pos.x].obj[(int)param] -= 1;
      cli->inventory[(int)param - 1] += 1;
      if ((int)param - 1 == 0)
	cli->life += (126 / zap->time_delay);
      redistribute_ressource(zap, (int)param - 1);
      answer(response_ok(), cli);
    }
  else
    answer(response_ko(), cli);
}

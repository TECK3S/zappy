/*
** act_fork.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 21:04:01 2011 rahman-serdar aysan
** Last update Sun Jul 10 21:04:37 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void	act_fork(action_param param __attribute__((unused)),
		 client * cli, zappy * zap)
{
  egg *	new_egg = NULL;

  if ((new_egg = malloc(sizeof(*new_egg))) != NULL)
    {
      zap->trantor[(cli->pos.y * zap->trantor_width)
		   + cli->pos.x].obj[EGGS] += 1;
      new_egg->num = zap->egg_numerotation;
      zap->egg_numerotation += 1;
      new_egg->team_name = strdup(cli->team_name);
      new_egg->time = 600 / zap->time_delay;
      new_egg->pos.x = cli->pos.x;
      new_egg->pos.y = cli->pos.y;
      new_egg->state = LAID;
      list_push_front(&zap->eggs, new_egg);
      answer(response_ok(), cli);
    }
}

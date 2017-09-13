/*
** act_sst.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 21:00:23 2011 rahman-serdar aysan
** Last update Tue Jul  5 19:27:42 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_sst(action_param param,
			client * cli,
			zappy * zap)
{
  double	new_timer;

  if (param == NO_PARAM)
    act_sgt(param, cli, zap);
  else
    {
      new_timer = atof((const char *)param);
      if (new_timer >= 1.0)
	zap->time_delay = new_timer;
      act_sgt(param, cli, zap);
      free(param);
    }
}

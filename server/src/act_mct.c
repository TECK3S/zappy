/*
** act_mct.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 20:53:51 2011 rahman-serdar aysan
** Last update Fri Jun 24 00:51:02 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void	act_mct(action_param param __attribute__((unused)),
		client * cli,
		zappy * zap __attribute__((unused)))
{
  t_pos	*	pos;
  size_t	i = 0;

  while (i < zap->trantor_width * zap->trantor_height)
    {
      if ((pos = malloc(sizeof(*pos))) == NULL)
	return ;
      pos->x = i % zap->trantor_width;
      pos->y = i / zap->trantor_height;
      act_bct(pos, cli, zap);
      ++i;
    }
}

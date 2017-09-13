/*
** act_graphic.c for act_graphic.c in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/server
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Jun 14 12:54:52 2011 eugene-valentin ngontang-tchiadjie
** Last update Mon Jul  4 21:57:47 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_msz(action_param param __attribute__((unused)),
			client * cli,
			zappy * zap)
{
  char *	msg;
  char		tmp[MAX_BUF_SIZE];
  int		len = 0;

  len += sprintf(tmp, " %i %i", zap->trantor_width, zap->trantor_height);
  if ((msg = malloc((strlen(MSZ_RESPONSE_CMD)
		     + len + 2) * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s %i %i\n", MSZ_RESPONSE_CMD,
	  zap->trantor_width, zap->trantor_height);
  answer(msg, cli);
}

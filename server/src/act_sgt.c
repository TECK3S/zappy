/*
** act_sgt.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 20:59:40 2011 rahman-serdar aysan
** Last update Tue Jul  5 19:27:07 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_sgt(action_param param __attribute__((unused)),
			client * cli,
			zappy * zap)
{
  char *	msg;
  char		tmp[MAX_BUF_SIZE];
  int		len = 0;

  len += sprintf(tmp, " %u", zap->time_delay);
  if ((msg = malloc((strlen(SGT_RESPONSE_CMD)
		     + len + 2) * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s %u\n", SGT_RESPONSE_CMD, zap->time_delay);
  answer(msg, cli);
}

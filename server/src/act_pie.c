/*
** act_pie.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 21:04:26 2011 rahman-serdar aysan
** Last update Wed Jun 22 21:04:58 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_pie(t_pos * pos, char R, client * gui)
{
  char *	msg;
  char		tmp[MAX_BUF_SIZE];
  int		len = 0;

  len += sprintf(tmp, " %i %i ", pos->x, pos->y);

  if ((msg = malloc((strlen(PIE_RESPONSE_CMD)
		     + len + 3) * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s %i %i %c", PIE_RESPONSE_CMD, pos->x, pos->y, R);
  answer(msg, gui);
}

/*
** act_enw.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 21:13:06 2011 rahman-serdar aysan
** Last update Mon Jul  4 21:47:16 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_enw(egg * e, client * host, client * gui)
{
  char *	msg;
  char		tmp[MAX_BUF_SIZE];
  int		len = 0;

  len += sprintf(tmp, " #%i #%i %i %i", e->num,
		 host->num, host->pos.x, host->pos.y);
  if ((msg = malloc((strlen(ENW_RESPONSE_CMD)
		     + len + 2) * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s #%i #%i %i %i\n", ENW_RESPONSE_CMD,
	  e->num, host->num, host->pos.x, host->pos.y);
  answer(msg, gui);
}

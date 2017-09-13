/*
** act_pnw.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 21:01:07 2011 rahman-serdar aysan
** Last update Tue Jul  5 19:25:25 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_pnw(client * host, client * gui)

{
  char *	msg;
  char		tmp[MAX_BUF_SIZE];
  int		len = 0;

  len += sprintf(tmp, "%i %i %i %i", host->num,
		 host->pos.x, host->pos.y, host->level);
  if ((msg = malloc((strlen(PNW_RESPONSE_CMD)
		     + strlen(host->team_name) + len + 6) * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s #%i %i %i %s %i %s\n", PNW_RESPONSE_CMD,
	  host->num, host->pos.x, host->pos.y,
	  get_client_dir(host->dir),
	  host->level, host->team_name);
  answer(msg, gui);
}

/*
** act_pex.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 21:01:50 2011 rahman-serdar aysan
** Last update Mon Jul  4 22:00:25 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_pex(client * host, client * gui)

{
  char *	msg;
  char		tmp[MAX_BUF_SIZE];
  int		len = 0;

  len += sprintf(tmp, "%i", host->num);
  if ((msg = malloc((strlen(PEX_RESPONSE_CMD)
		     + len + 4) * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s #%i\n", PEX_RESPONSE_CMD, host->num);
  answer(msg, gui);
}

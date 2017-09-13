/*
** act_pbc.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 21:02:29 2011 rahman-serdar aysan
** Last update Mon Jul  4 21:59:58 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_pbc(client * host, client * gui, char * smg)
{
  char *	msg;
  char		tmp[MAX_BUF_SIZE];
  int		len = 0;

  len += sprintf(tmp, "%i", host->num);
  if ((msg = malloc((strlen(PBC_RESPONSE_CMD) + strlen(smg)
		     + len + 5) * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s #%i %s\n", PBC_RESPONSE_CMD, host->num, smg);
  answer(msg, gui);
}

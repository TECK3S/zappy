/*
** act_pdr.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 21:10:24 2011 rahman-serdar aysan
** Last update Wed Jun 22 21:11:04 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_pdr(client * host, client * gui, int i)
{
  char *	msg;
  char		tmp[MAX_BUF_SIZE];
  int		len = 0;

  len += sprintf(tmp, " #%i %i", host->num, i);

  if ((msg = malloc((strlen(PDR_RESPONSE_CMD)
		     + len + 2) * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s #%i %i\n", PDR_RESPONSE_CMD, host->num, i);
  answer(msg, gui);
}

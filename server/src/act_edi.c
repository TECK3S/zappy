/*
** act_edi.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 21:15:24 2011 rahman-serdar aysan
** Last update Mon Jul  4 21:47:07 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_edi(egg * e, client * gui)
{
  char *	msg;
  char		tmp[MAX_BUF_SIZE];
  int		len = 0;

  len += sprintf(tmp, " #%i", e->num);
  if ((msg = malloc((strlen(EDI_RESPONSE_CMD)
		     + len + 2) * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s #%i\n", EDI_RESPONSE_CMD, e->num);
  answer(msg, gui);
}

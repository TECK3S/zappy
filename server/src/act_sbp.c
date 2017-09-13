/*
** act_sbp.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 21:17:38 2011 rahman-serdar aysan
** Last update Tue Jul  5 19:26:37 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_sbp(client * gui)
{
  char *	msg;

  if ((msg = malloc((strlen(SBP_RESPONSE_CMD) + 2) * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s\n", SBP_RESPONSE_CMD);
  answer(msg, gui);
}

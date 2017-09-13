/*
** act_seg.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 21:16:09 2011 rahman-serdar aysan
** Last update Tue Jul  5 19:26:55 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_seg(char * team_name, client * gui)
{
  char *	msg;

  if ((msg = malloc((strlen(SEG_RESPONSE_CMD)
		     + strlen(team_name) + 3)
		    * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s %s\n", SEG_RESPONSE_CMD, team_name);
  answer(msg, gui);
}

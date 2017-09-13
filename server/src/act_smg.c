/*
** act_smg.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 21:16:51 2011 rahman-serdar aysan
** Last update Tue Jul  5 19:27:20 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_smg(char * smg, client * gui)
{
  char *	msg;

  if ((msg = malloc((strlen(SMG_RESPONSE_CMD)
		     + strlen(smg) + 3)
		    * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s %s\n", SMG_RESPONSE_CMD, smg);
  answer(msg, gui);
}

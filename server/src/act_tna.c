/*
** act_tna.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 20:54:52 2011 rahman-serdar aysan
** Last update Tue Jul  5 19:28:00 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

static inline void	answer_tna(content_t * cont, param_t param)
{
  char *	msg;

  if ((msg = malloc((strlen(TNA_RESPONSE_CMD)
		     + strlen(((char *) *cont)) + 3) * sizeof(*msg))) == NULL)
    return ;
  sprintf(msg, "%s %s\n", TNA_RESPONSE_CMD, ((char *) *cont));
  answer(msg, (client *)param);
}

void		act_tna(action_param param __attribute__((unused)),
			client * cli,
			zappy * zap)
{
  list_iter(&zap->team_name, cli, answer_tna);
}

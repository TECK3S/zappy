/*
** act_ppo.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 20:56:49 2011 rahman-serdar aysan
** Last update Tue Jul  5 19:26:16 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_ppo(action_param param __attribute__((unused)),
			client * cli,
			zappy * zap __attribute__((unused)))
{
  char *	msg;
  client *	host;
  client	ref;
  char		tmp[MAX_BUF_SIZE];
  int		len = 0;

  if (param == NO_PARAM)
    answer(response_ko(), cli);
  else
    {
      ref.num = atoi((const char *)param);
      if (ref.num > 0 && (host = list_find(zap->client_list,
					   &ref, &get_client_by_num)) != NULL)
	{
	  len += sprintf(tmp, "%i %i %i", host->num, host->pos.x, host->pos.y);
	  if ((msg = malloc((strlen(PPO_RESPONSE_CMD)
			     + len + 5) * sizeof(*msg))) == NULL)
	    return ;
	  sprintf(msg, "%s #%i %i %i %s\n", PPO_RESPONSE_CMD,
		  host->num, host->pos.x, host->pos.y, get_client_dir(host->dir));
	  answer(msg, cli);
	  free(param);
	}
    }
}

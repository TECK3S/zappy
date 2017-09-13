/*
** act_plv.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 20:57:43 2011 rahman-serdar aysan
** Last update Tue Jul  5 19:24:50 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void		act_plv(action_param param,
			client * cli,
			zappy * zap __attribute__((unused)))
{
  char *	msg;
  char		tmp[MAX_BUF_SIZE];
  int		len = 0;
  client *	host;
  client	ref;

  if (param == NO_PARAM)
    answer(response_ko(), cli);
  else
    {
      ref.num = atoi((const char *)param);
      if (ref.num > 0 && (host = list_find(zap->client_list,
					   &ref, &get_client_by_num)) != NULL)
	{
	  len += sprintf(tmp, "%i %i", host->num, host->level);
	  if ((msg = malloc((strlen(PLV_RESPONSE_CMD)
			     + len + 4) * sizeof(*msg))) == NULL)
	    return ;
	  sprintf(msg, "%s #%i %i\n", PLV_RESPONSE_CMD, host->num, host->level);
	  answer(msg, cli);
	  free(param);
	}
    }
}

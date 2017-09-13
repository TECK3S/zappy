/*
** act_pin.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 20:58:36 2011 rahman-serdar aysan
** Last update Tue Jul  5 21:29:22 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"
static int	calc_len(client * host)
{
  char		tmp[MAX_BUF_SIZE];

  return (sprintf(tmp, "%i %i %i %i %i %i %i %i %i %i",
		  host->num, host->pos.x, host->pos.y,
		  host->inventory[0], host->inventory[1],
		  host->inventory[2], host->inventory[3],
		  host->inventory[4], host->inventory[5],
		  host->inventory[6]));
}

void		act_pin(action_param param,
			client * cli,
			zappy * zap __attribute__((unused)))
{
  char *	msg;
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
	  if ((msg = malloc((strlen(PIN_RESPONSE_CMD)
			     + calc_len(host) + 4) * sizeof(*msg))) == NULL)
	    return ;
	  sprintf(msg, "%s #%i %i %i %i %i %i %i %i %i %i\n",
		  PIN_RESPONSE_CMD, host->num, host->pos.x, host->pos.y,
		  host->inventory[0], host->inventory[1],
		  host->inventory[2], host->inventory[3],
		  host->inventory[4], host->inventory[5],
		  host->inventory[6]);
	  answer(msg, cli);
	  free(param);
	}
    }
}

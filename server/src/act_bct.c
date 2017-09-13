/*
** act_bct.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
   Last update Tue Jul  5 23:36:17 2011 eugene-valentin ngontang-tchiadjie
** Last update Tue Jul  5 19:14:20 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

static int	calc_len(zappy * zap, t_pos * pos, int i)
{
  char		tmp[MAX_BUF_SIZE];

  return (sprintf(tmp, " %i %i %i %i %i %i %i %i %i %i %i", pos->x, pos->y,
		  zap->trantor[i].obj[PLAYER], zap->trantor[i].obj[FOOD],
		  zap->trantor[i].obj[LINEMATE], zap->trantor[i].obj[DERAUMERE],
		  zap->trantor[i].obj[SIBUR], zap->trantor[i].obj[MENDIANE],
		  zap->trantor[i].obj[PHIRAS], zap->trantor[i].obj[THYSTAME],
		  zap->trantor[i].obj[EGGS]));
}

void	act_bct(action_param param __attribute__((unused)),
		client * cli,
		zappy * zap)
{
  char *	msg;
  t_pos	*	pos;
  size_t	i = 0;

  if (param == NO_PARAM)
    answer(response_ko(), cli);
  else
    {
      pos = ((t_pos *)param);
      if ((i = (pos->y * zap->trantor_width) + pos->x)
	  < (zap->trantor_width * zap->trantor_height))
	{
	  if ((msg = malloc((strlen(BCT_RESPONSE_CMD)
			     + calc_len(zap, pos, i) + 2) * sizeof(*msg))) == NULL)
	    return ;
	  sprintf(msg, "%s %i %i %i %i %i %i %i %i %i %i %i\n", BCT_RESPONSE_CMD,
		  pos->x, pos->y, zap->trantor[i].obj[PLAYER],
		  zap->trantor[i].obj[FOOD], zap->trantor[i].obj[LINEMATE],
		  zap->trantor[i].obj[DERAUMERE], zap->trantor[i].obj[SIBUR],
		  zap->trantor[i].obj[MENDIANE], zap->trantor[i].obj[PHIRAS],
		  zap->trantor[i].obj[THYSTAME], zap->trantor[i].obj[EGGS]);
	  answer(msg, cli);
	}
      free(param);
    }
}

/*
** action_graphic.c for graphic.c in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/server/src
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Mon Jun 13 19:05:48 2011 eugene-valentin ngontang-tchiadjie
** Last update Mon Jul  4 21:56:59 2011 adrien barrau
*/

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "zappy.h"

static inline void		no_overflow(int * found, int * i)
{
  *found = 1;
  *i = MAX_BUF_SIZE - 1;
}

static inline t_action *	get_action_graphic(buffer * b)
{
  char			buffer[MAX_BUF_SIZE];
  int			i = 0, count = b->begin, found = 0;

  while (!found)
    {
      if (b->data[count] == '\n')
	found = 1;
      buffer[i++] = b->data[count++];
      if (i >= MAX_BUF_SIZE)
	no_overflow(&found, &i);
      if (!found && count == b->end)
	found = -1;
      if (!found && count >= MAX_BUF_SIZE)
	count = 0;
    }
  if (found == 1)
    {
      buffer[i] = '\0';
      printf("[GUI] %s\n", buffer);
      b->begin = count;
      return (parse_graphic_cmd(buffer));
    }
  return (NULL);
}

static inline int		exec_action_graphic(t_action * action,
						    client * host,
						    zappy * zap)
{
  static void (*action_tab[])(action_param, client *, zappy *) =
    {
      NULL,
      &act_msz,
      &act_bct,
      &act_mct,
      &act_tna,
      &act_ppo,
      &act_plv,
      &act_pin,
      &act_sgt,
      &act_sst
    };

  if (action->id > 0 && action->id <= CONNECT_NBR_ID)
    {
      action_tab[action->id](action->param, host, zap);
      return (NO_ERR_CODE);
    }
  free(action);
  return (EXEC_ERR_CODE);
}

int		action_graphic(zappy * zap, client * cli)
{
  int		errcode = NO_ERR_CODE;
  t_action *	action = NULL;

  if ((action = get_action_graphic(&cli->read_buffer)) != NULL)
    errcode = exec_action_graphic(action, cli, zap);
  return (errcode);
}

/*
** action_connected.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server/src
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Mon Jun 13 18:16:27 2011 adrien barrau
** Last update Mon Jul  4 21:56:07 2011 adrien barrau
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

static inline t_action *	get_connected_action(buffer * b)
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
      printf("[Connected player] %s\n", buffer);
      b->begin = count;
      return (parse_connected_cmd(buffer));
    }
  return (NULL);
}

static inline int		exec_action_connected(t_action * action,
						      client * host,
						      zappy * zap)
{
  static void (*action_tab[])(action_param, client *, zappy *) =
    {
      NULL,
      &act_equipe,
      &act_graphic
    };

  if (action->id > 0 && action->id <= GRAPHIC_ID)
    {
      action_tab[action->id](action->param, host, zap);
      return (NO_ERR_CODE);
    }
  free(action);
  return (EXEC_ERR_CODE);
}

int		action_connected(zappy * zap, client * cli)
{
  int		errcode = NO_ERR_CODE;
  t_action *	action = NULL;

  if ((action = get_connected_action(&cli->read_buffer)) != NULL)
    errcode = exec_action_connected(action, cli, zap);
  return (errcode);
}

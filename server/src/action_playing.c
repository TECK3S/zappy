/*
** action_playing.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server/src
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Mon Jun 13 18:14:48 2011 adrien barrau
** Last update Mon Jul  4 21:57:14 2011 adrien barrau
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

static inline t_action *	get_action_playing(buffer * b, zappy * zap)
{
  char			buffer[MAX_BUF_SIZE];
  int			i = 0;
  int			count = b->begin;
  int			found = 0;

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
      printf("[Playing player] %s\n", buffer);
      b->begin = count;
      return (parse_playing_cmd(buffer, zap));
    }
  return (NULL);
}

int		exec_action_playing(t_action * action, client * host, zappy * zap)
{
  static void (*action_tab[])(action_param, client *, zappy *) =
    {
      NULL,
      &act_avance,
      &act_droite,
      &act_gauche,
      &act_voir,
      &act_inventaire,
      &act_prend,
      &act_pose,
      &act_expulse,
      &act_broadcast,
      &act_incantation,
      &act_fork,
      &act_connect_nbr
    };

  if (action->id > 0 && action->id <= CONNECT_NBR_ID)
    {
      action_tab[action->id](action->param, host, zap);
      return (NO_ERR_CODE);
    }
  free(action);
  return (EXEC_ERR_CODE);
}

int		action_playing(zappy * zap,
			       client * cli)
{
  int		errcode = NO_ERR_CODE;
  t_action *	action = NULL;

  if ((action = get_action_playing(&cli->read_buffer, zap)) != NULL
      && (cli->last_act + 1) % 11 != cli->current_act)
    {
      cli->action[cli->last_act] = action;
      cli->last_act = (cli->last_act + 1) % 11;
    }
  return (errcode);
}


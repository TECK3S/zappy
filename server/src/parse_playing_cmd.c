/*
** parse_cmd.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server/src
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Jun  2 11:50:35 2011 adrien barrau
** Last update Sun Jul 10 22:04:48 2011 rahman-serdar aysan
*/

#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "zappy.h"

static inline t_action *	cmd_expulse(char * cmd, zappy * zap)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, EXPULSE_CMD, strlen(EXPULSE_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = EXPULSE_ID;
      act->param = NO_PARAM;
      act->time = 7 / zap->time_delay;
    }
  return (act);
}

static inline size_t	strpos(char * s, char c)
{
  size_t	pos = 0;

  while (s[pos])
    {
      if (s[pos] == c)
	break;
      pos++;
    }
  return (pos);
}

static inline t_action *	cmd_broadcast(char * cmd, zappy * zap)
{
  t_action *		act = NULL;
  int			i = 0;

  if (strncasecmp(cmd, BROADCAST_CMD, strlen(BROADCAST_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = BROADCAST_ID;
      i = strlen(BROADCAST_CMD);
      while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
	++i;
      act->param = strndup(&(cmd[i]), strpos(cmd, '\n') - i);
      act->time = 7 / zap->time_delay;
    }
  return (act);
}

static inline t_action *	cmd_connect_nbr(char * cmd,
						zappy * zap __attribute__((unused)))
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, CONNECT_NBR_CMD, strlen(CONNECT_NBR_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = CONNECT_NBR_ID;
      act->param = NO_PARAM;
      act->time = 0;
    }
  return (act);
}

static t_action * (*cmds[])(char *, zappy *)=
 {
  &cmd_avance,
  &cmd_droite,
  &cmd_gauche,
  &cmd_voir,
  &cmd_inventaire,
  &cmd_prend,
  &cmd_pose,
  &cmd_expulse,
  &cmd_broadcast,
  &cmd_incantation,
  &cmd_fork,
  &cmd_connect_nbr,
  0
 };

t_action *	parse_playing_cmd(char * cmd, zappy * zap)
{
  int		i = 0, j = 0;
  t_action *	act = NULL;

  if (!cmd)
    return (NULL);
  while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
    ++i;
  while (cmds[j])
    {
      if ((act = cmds[j](&(cmd[i]), zap)) != NULL)
	break;
      ++j;
    }
  return (act);
}

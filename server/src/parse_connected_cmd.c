/*
** parse_connected_cmd.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server/src
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Mon Jun 13 18:28:17 2011 adrien barrau
** Last update Fri Jun 24 00:50:57 2011 adrien barrau
*/

#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "zappy.h"

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

static inline t_action *	cmd_equipe(char * cmd)
{
  t_action *		act = NULL;
  int			i = 0;

  if (strncasecmp(cmd, EQUIPE_CMD, strlen(EQUIPE_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = EQUIPE_ID;
      i = strlen(EQUIPE_CMD);
      while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
	++i;
      act->param = strndup(&(cmd[i]), strpos(cmd, '\n') - i);
      act->time = 0;
    }
  return (act);
}

static inline t_action *	cmd_graphic(char * cmd)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, GRAPHIC_CMD, strlen(GRAPHIC_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = GRAPHIC_ID;
      act->param = NO_PARAM;
      act->time = 0;
    }
  return (act);
}

static t_action * (*cmds[])(char *)=
{
  &cmd_equipe,
  &cmd_graphic,
  0
};

t_action *	parse_connected_cmd(char * cmd)
{
  int		i = 0, j = 0;
  t_action *	act = NULL;

  if (!cmd)
    return (NULL);
  while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
    ++i;
  while (cmds[j])
    {
      if ((act = cmds[j](&(cmd[i]))) != NULL)
	break;
      ++j;
    }
  return (act);
}

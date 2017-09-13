/*
** cmd_protocol_suite.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 22:12:46 2011 rahman-serdar aysan
** Last update Sun Jul 10 22:14:17 2011 rahman-serdar aysan
*/

#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

t_action *		cmd_plv(char * cmd)
{
  t_action *		act = NULL;
  int			i = strlen(PLV_CMD);

  if (strncasecmp(cmd, PLV_CMD, strlen(PLV_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = PLV_ID;
      while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
	++i;
      if (cmd[i] != '#')
	act->param = NO_PARAM;
      else if (!cmd[i + 1])
	act->param = NO_PARAM;
      else
	act->param = strdup(&cmd[i + 1]);
      act->time = 0;
    }
  return (act);
}

t_action *		cmd_pin(char * cmd)
{
  t_action *		act = NULL;
  int			i = strlen(PIN_CMD);

  if (strncasecmp(cmd, PIN_CMD, strlen(PIN_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = PIN_ID;
      while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
	++i;
      if (cmd[i] != '#')
	act->param = NO_PARAM;
      else if (!cmd[i + 1])
	act->param = NO_PARAM;
      else
	act->param = strdup(&cmd[i + 1]);
      act->time = 0;
    }
  return (act);
}

t_action *		cmd_sgt(char * cmd)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, SGT_CMD, strlen(SGT_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = SGT_ID;
      act->param = NO_PARAM;
      act->time = 0;
    }
  return (act);
}

t_action *		cmd_sst(char * cmd)
{
  t_action *		act = NULL;
  int			i = strlen(PIN_CMD);

  if (strncasecmp(cmd, SST_CMD, strlen(SST_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = SST_ID;
      while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
	++i;
      if (!cmd[i])
	act->param = NO_PARAM;
      else
	act->param = strdup(&cmd[i]);
      act->time = 0;
    }
  return (act);
}

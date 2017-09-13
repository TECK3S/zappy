/*
** cmd_protocol.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 22:07:40 2011 rahman-serdar aysan
** Last update Sun Jul 10 22:09:21 2011 rahman-serdar aysan
*/

#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

t_action *		cmd_msz(char * cmd)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, MSZ_CMD, strlen(MSZ_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = MSZ_ID;
      act->param = NO_PARAM;
      act->time = 0;
    }
  return (act);
}

t_action *		cmd_bct(char * cmd)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, BCT_CMD, strlen(BCT_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = BCT_ID;
      act->time = 0;
      if ((act->param = (void *)get_pos(&(cmd[strlen(BCT_CMD)]))) == 0)
	{
	  free(act);
	  act = NULL;
	}
    }
  return (act);
}
t_action *		cmd_mct(char * cmd)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, MCT_CMD, strlen(MCT_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = MCT_ID;
      act->param = NO_PARAM;
      act->time = 0;
    }
  return (act);
}

t_action *		cmd_tna(char * cmd)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, TNA_CMD, strlen(TNA_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = TNA_ID;
      act->param = NO_PARAM;
      act->time = 0;
    }
  return (act);
}

t_action *		cmd_ppo(char * cmd)
{
  t_action *		act = NULL;
  int			i = strlen(PPO_CMD);

  if (strncasecmp(cmd, PPO_CMD, strlen(PPO_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = PPO_ID;
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

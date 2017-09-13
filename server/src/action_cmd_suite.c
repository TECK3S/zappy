/*
** action_cmd_suite.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 21:53:41 2011 rahman-serdar aysan
** Last update Sun Jul 10 21:57:34 2011 rahman-serdar aysan
*/

#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "zappy.h"

static char * objets[]=
  {
    UNUSED_OBJ,
    FOOD_OBJ,
    LINEMATE_OBJ,
    DERAUMERE_OBJ,
    SIBUR_OBJ,
    MENDIANE_OBJ,
    PHIRAS_OBJ,
    THYSTAME_OBJ,
    0
  };

static inline enum eObjectType get_objet(char * obj)
{
  int		i = 0, j = 1;

  if (!obj)
    return (0);
  while (obj[i] && (obj[i] == ' ' || obj[i] == '\t'))
    ++i;
  while (objets[j])
    {
      if (strncasecmp(&(obj[i]), objets[j], strlen(objets[j])) == 0)
	return (j);
      ++j;
    }
  return (0);
}

t_action *		cmd_prend(char * cmd, zappy * zap)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, PREND_CMD, strlen(PREND_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = PREND_ID;
      act->time = 7 / zap->time_delay;
      if ((act->param = (void *)get_objet(&(cmd[strlen(PREND_CMD)]))) == 0)
	{
	  free(act);
	  act = NULL;
	}
    }
  return (act);
}

t_action *		cmd_pose(char * cmd, zappy * zap)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, POSE_CMD, strlen(POSE_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = POSE_ID;
      act->time = 7 / zap->time_delay;
      if ((act->param = (void *)get_objet(&(cmd[strlen(POSE_CMD)]))) == 0)
	{
	  free(act);
	  act = NULL;
	}
    }
  return (act);
}

t_action *		cmd_incantation(char * cmd, zappy * zap)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, INCANTATION_CMD, strlen(INCANTATION_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = INCANTATION_ID;
      act->param = NO_PARAM;
      act->time = 300 / zap->time_delay;
    }
  return (act);
}

t_action *		cmd_fork(char * cmd, zappy * zap)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, FORK_CMD, strlen(FORK_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = FORK_ID;
      act->param = NO_PARAM;
      act->time = 42 / zap->time_delay;
    }
  return (act);
}

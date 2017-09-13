/*
** action_cmd.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 21:46:50 2011 rahman-serdar aysan
** Last update Sun Jul 10 21:48:26 2011 rahman-serdar aysan
*/

#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "zappy.h"

t_action *		cmd_avance(char * cmd, zappy * zap)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, AVANCE_CMD, strlen(AVANCE_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = AVANCE_ID;
      act->param = NO_PARAM;
      act->time = 7 / zap->time_delay;
    }
  return (act);
}

t_action *		cmd_droite(char * cmd, zappy * zap)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, DROITE_CMD, strlen(DROITE_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = DROITE_ID;
      act->param = NO_PARAM;
      act->time = 7 / zap->time_delay;
    }
  return (act);
}

t_action *		cmd_gauche(char * cmd, zappy * zap)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, GAUCHE_CMD, strlen(GAUCHE_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = GAUCHE_ID;
      act->param = NO_PARAM;
      act->time = 7 / zap->time_delay;
    }
  return (act);
}

t_action *		cmd_voir(char * cmd, zappy * zap)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, VOIR_CMD, strlen(VOIR_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = VOIR_ID;
      act->param = NO_PARAM;
      act->time = 7 / zap->time_delay;
    }
  return (act);
}

t_action *		cmd_inventaire(char * cmd, zappy * zap)
{
  t_action *		act = NULL;

  if (strncasecmp(cmd, INVENTAIRE_CMD, strlen(INVENTAIRE_CMD)) == 0)
    {
      if ((act = malloc(sizeof(*act))) == NULL)
	return (NULL);
      act->id = INVENTAIRE_ID;
      act->param = NO_PARAM;
      act->time = 1 / zap->time_delay;
    }
  return (act);
}

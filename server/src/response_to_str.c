/*
** response_to_str.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server/src
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Jun  2 14:17:15 2011 adrien barrau
** Last update Sun Jul 10 22:32:52 2011 rahman-serdar aysan
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "socket.h"
#include "zappy.h"

char *	response_mort()
{
  char *	resp = NULL;

  if ((resp = malloc((strlen(MORT_RESPONSE_CMD) + 2) * sizeof(*resp))) == NULL)
    return (NULL);
  sprintf(resp, "%s\n", MORT_RESPONSE_CMD);
  return (resp);
}

char *	response_bienvenue()
{
  char *	resp = NULL;

  if ((resp = malloc((strlen(BIENVENUE_RESPONSE_CMD)
		      + strlen(MOTD) + 3) * sizeof(*resp))) == NULL)
    return (NULL);
  sprintf(resp, "%s %s\n", BIENVENUE_RESPONSE_CMD, MOTD);
  return (resp);
}

char *	response_gagner(char * team_name)
{
  char *	resp = NULL;

  if ((resp = malloc((strlen(GAGNER_RESPONSE_CMD)
		      + strlen(team_name) + 3) * sizeof(*resp))) == NULL)
    return (NULL);
  sprintf(resp, "%s %s\n", GAGNER_RESPONSE_CMD, team_name);
  return (resp);
}

void	answer(char * msg, client * cli)
{
  if (msg && cli)
    {
      fill_buffer(&cli->write_buffer, msg, strlen(msg));
      socket_write(&cli->write_buffer, cli->socket);
      free(msg);
    }
}

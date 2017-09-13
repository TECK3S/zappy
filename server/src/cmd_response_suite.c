/*
** cmd_response_suite.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 22:31:35 2011 rahman-serdar aysan
** Last update Sun Jul 10 22:33:19 2011 rahman-serdar aysan
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "socket.h"
#include "zappy.h"

char *	response_objets(int * objs)
{
  char *	resp = NULL;
  int		len = 0, i = 0;
  char		len_calc[1024];

  while (i < 7)
    len += sprintf(len_calc, "%i", objs[i++]);
  if ((resp = malloc((strlen(OBJETS_RESPONSE_CMD) + 24 + len
		      + strlen(FOOD_OBJ) + strlen(LINEMATE_OBJ)
		      + strlen(DERAUMERE_OBJ) + strlen(SIBUR_OBJ)
		      + strlen(MENDIANE_OBJ) + strlen(PHIRAS_OBJ)
		      + strlen(THYSTAME_OBJ)) * sizeof(*resp))) == NULL)
    return (NULL);
  sprintf(resp, "%s {%s %i, %s %i, %s %i, %s %i, %s %i, %s %i, %s %i}\n",
	  OBJETS_RESPONSE_CMD, FOOD_OBJ, objs[0], LINEMATE_OBJ, objs[1],
	  DERAUMERE_OBJ, objs[2], SIBUR_OBJ, objs[3], MENDIANE_OBJ, objs[4],
	  PHIRAS_OBJ, objs[5], THYSTAME_OBJ, objs[6]);
  return (resp);
}

char *	response_deplacement(int position)
{
  char *	resp = NULL;

  if (position < 9 && position > 0)
    {
      if ((resp = malloc((strlen(DEPLACEMENT_RESPONSE_CMD)
			  + 4) * sizeof(*resp))) == NULL)
	return (NULL);
      sprintf(resp, "%s %i\n", DEPLACEMENT_RESPONSE_CMD, position);
    }
  return (resp);
}

char *	response_message(char * msg, int position)
{
  char *	resp = NULL;

  if (position >= 0 && position < 9 && msg)
    {
      if ((resp = malloc((strlen(MESSAGE_RESPONSE_CMD)
			  + strlen(msg) + 6) * sizeof(*resp))) == NULL)
	return (NULL);
      sprintf(resp, "%s %i, %s\n", MESSAGE_RESPONSE_CMD, position, msg);
    }
  return (resp);
}

char *	response_elevation(int level)
{
  char *	resp = NULL;

  if (level > 0 && level < 10)
    {
      if ((resp = malloc((strlen(ELEVATION_RESPONSE_CMD)
			  + 4) * sizeof(*resp))) == NULL)
	return (NULL);
      sprintf(resp, "%s %i\n", ELEVATION_RESPONSE_CMD, level);
    }
  return (resp);
}

char *	response_slot(int slot_dispo, int slot_total)
{
  char *	resp = NULL;
  char		len_dispo[1024];
  char		len_total[1024];

  if (slot_dispo >= 0
      && slot_dispo <= MAX_SLOT_PER_TEAM
      && slot_total >= 0
      && slot_total <= MAX_SLOT_PER_TEAM)
    {
      sprintf(len_dispo, "%i", slot_dispo);
      sprintf(len_total, "%i", slot_total);
      if ((resp = malloc((strlen(SLOT_RESPONSE_CMD)
			  + strlen(len_dispo) + strlen(len_total)
			  + 4) * sizeof(*resp))) == NULL)
	return (NULL);
      sprintf(resp, "%s %i/%i\n", SLOT_RESPONSE_CMD, slot_dispo, slot_total);
    }
  return (resp);
}

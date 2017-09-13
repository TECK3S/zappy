/*
** cmd_response.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 22:29:09 2011 rahman-serdar aysan
** Last update Sun Jul 10 22:30:49 2011 rahman-serdar aysan
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "socket.h"
#include "zappy.h"

char *	response_ok()
{
  char *	resp = NULL;

  if ((resp = malloc((strlen(OK_RESPONSE_CMD) + 2) * sizeof(*resp))) == NULL)
    return (NULL);
  sprintf(resp, "%s\n", OK_RESPONSE_CMD);
  return (resp);
}

char *	response_ko()
{
  char *	resp = NULL;

  if ((resp = malloc((strlen(KO_RESPONSE_CMD) + 2) * sizeof(*resp))) == NULL)
    return (NULL);
  sprintf(resp, "%s\n", KO_RESPONSE_CMD);
  return (resp);
}

static char * objets[]=
  {
    PLAYER_OBJ,
    FOOD_OBJ,
    LINEMATE_OBJ,
    DERAUMERE_OBJ,
    SIBUR_OBJ,
    MENDIANE_OBJ,
    PHIRAS_OBJ,
    THYSTAME_OBJ,
    EGGS_OBJ,
    0
  };

static inline void	vision_objects(void ** objectss, void * p)
{
  char *	resp = (char *)p;
  int		i = 0, j = 0;
  objects *	objs = (objects *)*objectss;

  for (i = 0; i < 9; ++i)
    {
      for (j = 0; j < objs->obj[i]; ++j)
	{
	  strcat(resp, objets[i]);
	  strcat(resp, " ");
	}
    }
  strcat(resp, ",");
}

char *		response_vision(t_list * vision_list)
{
  char * resp = NULL;

  if ((resp = malloc(9999 * sizeof(*resp))) == NULL)
    return (NULL);
  sprintf(resp, "%s { ", VISION_RESPONSE_CMD);
  list_iter(vision_list, resp, &vision_objects);
  sprintf(&(resp[strlen(resp) - 1]), "}\n");
  return (resp);
}

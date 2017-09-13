/*
** egg.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Jun 23 20:27:39 2011 adrien barrau
** Last update Tue Jul  5 19:29:12 2011 adrien barrau
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"

static inline bool_t	get_hatched_egg(const content_t ref,
					const content_t cur)
{
  egg *		the_egg = (egg *)cur;

  if (the_egg->state == HATCHED
      && strcmp(the_egg->team_name, (char *)ref) == 0)
    return (TRUE);
  return (FALSE);
}

static inline bool_t	get_full_egg(const content_t ref, const content_t cur)
{
  egg *		the_egg = (egg *)cur;

  if (the_egg->state == FULL
      && strcmp(the_egg->team_name, (char *)ref) == 0)
    return (TRUE);
  return (FALSE);
}

int	join_from_egg(client * cli, zappy * zap, char * team_name)
{
  egg *	the_egg = list_find(zap->eggs, team_name, &get_hatched_egg);

  if (the_egg)
    {
      the_egg->state = FULL;
      zap->trantor[(the_egg->pos.y * zap->trantor_width)
		   + the_egg->pos.x].obj[EGGS] -= 1;
      cli->team_name = strdup(team_name);
      cli->pos.x = the_egg->pos.x;
      cli->pos.y = the_egg->pos.y;
      zap->trantor[(cli->pos.y * zap->trantor_width)
		   + cli->pos.x].obj[PLAYER] += 1;
      cli->inventory[0] = 10;
      cli->state = PLAYING;
      cli->dir = rand() % 4;
      cli->level = 1;
      cli->num = zap->player_numerotation;
      zap->player_numerotation += 1;
      cli->life = 10 * (126 / zap->time_delay);
      answer(response_ok(), cli);
      printf("[System] A new player is joining team %s by an egg\n",
	     team_name);
      return (true);
    }
  return (false);
}

void	destroy_full_egg(zappy * zap, char * team_name)
{
  list_remove(&zap->eggs, team_name, &get_full_egg);
}

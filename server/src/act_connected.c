/*
** act_connected.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Mon Jun 13 18:46:30 2011 adrien barrau
** Last update Sun Jul 10 20:42:34 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

static inline void	get_full_eggs(content_t * cont,
				      param_t param1,
				      param_t param2)
{
  egg *		the_egg = (egg *)*cont;
  char *	team_name = (char *)param1;
  int *		nb = (int *)param2;

  if (the_egg->state == FULL
      && strcmp(the_egg->team_name, team_name) == 0)
    *nb = *nb + 1;
}

static inline void	get_playing_player(content_t * cont,
					   param_t param1,
					   param_t param2)
{
  client *	cli = (client *)*cont;
  char *	team_name = (char *)param1;
  int *		nb = (int *)param2;

  if (cli->state == PLAYING
      && strcmp(cli->team_name, team_name) == 0)
    *nb = *nb + 1;
}

static inline int	a_place_for_player(zappy * zap,
					   char * team_name)
{
  size_t	nb_playing_player = 0, nb_full_eggs = 0;

  list_iter2(&zap->client_list,
	     team_name,
	     &nb_playing_player,
	     &get_playing_player);
  list_iter2(&zap->eggs,
	     team_name,
	     &nb_full_eggs,
	     &get_full_eggs);
  if (nb_playing_player < (zap->slot_per_team + nb_full_eggs))
    return (true);
  return (false);
}

static inline void	create_random_cli(client * cli,
					  zappy * zap,
					  char * team_name)
{
  cli->team_name = strdup(team_name);
  cli->pos.x = rand() % zap->trantor_width;
  cli->pos.y = rand() % zap->trantor_height;
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
  printf("[System] A new player is joining team %s\n", team_name);
}

void	act_equipe(action_param param,
		   client * cli,
		   zappy * zap)
{
  if (list_find(zap->team_name, param, &find_team))
    {
      if (!join_from_purgatory(cli, zap, (char *)param)
	  && !join_from_egg(cli, zap, (char *)param))
	{
	  if (a_place_for_player(zap, (char *)param))
	    create_random_cli(cli, zap, (char *)param);
	  else
	    answer(response_ko(), cli);
	}
    }
  else
    answer(response_ko(), cli);
  free(param);
}

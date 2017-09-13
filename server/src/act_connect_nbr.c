/*
** act_connect_nbr.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 21:15:05 2011 rahman-serdar aysan
** Last update Sun Jul 10 21:15:45 2011 rahman-serdar aysan
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

void		act_connect_nbr(action_param param __attribute__((unused)),
				client * cli, zappy * zap)
{
  size_t	nb_playing_player = 0, nb_total = zap->slot_per_team;

  list_iter2(&zap->client_list, cli->team_name,
	     &nb_playing_player, &get_playing_player);
  list_iter2(&zap->eggs, cli->team_name, &nb_total, &get_full_eggs);
  answer(response_slot(nb_total - nb_playing_player, nb_total), cli);
}

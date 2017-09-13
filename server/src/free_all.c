/*
** free_all.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Mon Jul  4 18:36:19 2011 adrien barrau
** Last update Tue Jul  5 19:29:47 2011 adrien barrau
*/

#include <stdlib.h>
#include <unistd.h>
#include "zappy.h"
#include "socket.h"

static void	free_team_name(content_t * cont,
			       param_t p __attribute__((unused)))
{
  client *	cli = (client *)*cont;

  if (cli->state == PLAYING
      || cli->state == OVER)
    free(cli->team_name);
}

void	free_all(zappy * zap, struct epoll_event * events)
{
  free(zap->trantor);
  list_clear_nofree(&zap->team_name);
  list_iter(&zap->client_list, NULL, &free_team_name);
  list_clear(&zap->client_list);
  list_clear(&zap->eggs);
  list_iter(&zap->purgatory, NULL, &free_team_name);
  list_clear(&zap->purgatory);
  free(events);
}

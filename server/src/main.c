/*
** main.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Jun  1 10:17:39 2011 adrien barrau
** Last update Fri Jun 24 00:44:36 2011 adrien barrau
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "errors.h"
#include "zappy.h"

bool	SERVER_ENDED = false;

static char *	errors[]=
  {
    NO_ERR_MSG,
    TOO_LARGE_ERR_MSG,
    TOO_HEIGHT_ERR_MSG,
    TOO_MANY_SLOTS_ERR_MSG,
    PARSE_OPT_ERR_MSG,
    SOCK_ERR_MSG,
    LISTEN_ERR_MSG,
    FDS_ERR_MSG,
    MEMORY_ERR_MSG,
    EPOLL_CREATE_ERR_MSG,
    ACCEPT_ERR_MSG,
    POLL_ERR_MSG,
    LIST_ADD_ERR_MSG,
    LIST_DEL_ERR_MSG,
    SIGFILLLSET_ERR_MSG,
    EXEC_ERR_MSG
  };

static inline void	init_zap(zappy * zap)
{
  zap->socket = 0;
  zap->client_list = EMPTY;
  zap->trantor = EMPTY;
  zap->trantor_width = 0;
  zap->trantor_height = 0;
  zap->slot_per_team = 0;
  zap->time_delay = 0;
  zap->team_name = EMPTY;
  zap->max_clients = 10;
  zap->current_clients = 0;
  zap->player_numerotation = 1;
  zap->eggs = EMPTY;
  zap->egg_numerotation = 1;
  zap->purgatory = EMPTY;
  init_sigaction();
}

int		main(int ac, char ** av)
{
  int		errcode = 0;
  zappy		zap;
  int		port = 0;

  srand(time(NULL));
  init_zap(&zap);
  errcode = parse_args(ac, av, &zap, &port);
  if (!errcode)
    errcode = init_trantor(&zap);
  if (!errcode)
    errcode = zappy_server(&zap, port);
  if (errcode)
    fprintf(stderr, "./zappy : Error : %s\n", errors[errcode * -1]);
  return (errcode);
}

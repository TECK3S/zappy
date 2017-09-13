/*
** init_sigaction.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Jun 21 17:20:13 2011 adrien barrau
** Last update Fri Jun 24 02:30:56 2011 adrien barrau
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

void	end_server(int num, siginfo_t * info, void * context)
{
  extern bool	SERVER_ENDED;

  (void)info;
  (void)context;
  if (num == SIGINT)
    fprintf(stderr, "[System] Receiving Signal [^C]: Ending server..\n");
  else if (num == SIGQUIT)
    fprintf(stderr, "[System] Receiving Signal [^\\]: Ending server..\n");
  else
    fprintf(stderr, "[System] Receiving Unhandled Signal: Ending server..\n");
  SERVER_ENDED = true;
}

int	init_sigaction(void)
{
  struct sigaction	act;
  int			errcode = NO_ERR_CODE;

  act.sa_handler = NULL;
  sigfillset(&act.sa_mask);
  act.sa_sigaction = &end_server;
  act.sa_flags = SA_SIGINFO;
  if (sigaction(SIGINT, &act, NULL) == -1)
    errcode = NO_ERR_CODE;
  if (sigaction(SIGQUIT, &act, NULL) == -1)
    errcode = NO_ERR_CODE;
  return (errcode);
}

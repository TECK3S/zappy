/*
** get_command.c for get_command.c in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/server
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Fri Jun  3 16:14:28 2011 eugene-valentin ngontang-tchiadjie
** Last update Fri Jun 24 00:50:57 2011 adrien barrau
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "socket.h"

static int (*client_action_tab[])(zappy *, client *)=
{
  &action_connected,
  &action_graphic,
  &action_playing,
  0
};

int		get_command(zappy * zap, int sock)
{
  client	ref;
  client *	host;
  int		errcode = NO_ERR_CODE;

  ref.socket = sock;
  host = list_find(zap->client_list, &ref, &get_client_by_socket);
  if (host && host->state != OVER)
    {
      socket_read(&host->read_buffer, host->socket);
      errcode = client_action_tab[host->state](zap, host);
    }
  return (errcode);
}

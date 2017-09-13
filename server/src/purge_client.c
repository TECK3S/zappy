/*
** purge_client.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Jun 21 20:48:38 2011 adrien barrau
** Last update Tue Jul  5 21:33:03 2011 adrien barrau
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include "zappy.h"
#include "socket.h"

int	purge_client(zappy * zap,
		     struct epoll_event * event,
		     struct epoll_event * ev,
		     int epfd)
{
  int		errcode = NO_ERR_CODE;
  client	ref, *cli = NULL;

  if ((errcode = epoll_ctl(epfd, EPOLL_CTL_DEL, event->data.fd, ev)) == -1)
    fprintf(stderr, "[System] Error when removing socket from poll\n");
  else
    errcode = socket_close(event->data.fd);
  ref.socket = event->data.fd;
  if ((cli = (client *)list_find(zap->client_list, &ref,
	 &get_client_by_socket)) != NULL && cli->state == PLAYING)
    {
      printf(PURGE_MSG);
      list_remove_nofree(&zap->client_list, &ref, &get_client_by_socket);
      cli->socket = 0;
      list_push_front(&zap->purgatory, cli);
    }
  else
    {
      printf("[System] The remote client has disconnected suddently\n");
      if (cli)
	free(cli->team_name);
      if (!list_remove(&zap->client_list, &ref, &get_client_by_socket))
	errcode = LIST_DEL_ERR_CODE;
    }
  return (errcode);
}

static inline bool_t	get_client_by_team(const content_t ref,
					   const content_t cur)
{
  if (strcmp(((char *)ref), ((client *)cur)->team_name) == 0)
    return (TRUE);
  return (FALSE);
}

static inline bool_t	get_client_by_addr(const content_t ref,
					   const content_t cur)
{
  if (ref == cur)
    return (TRUE);
  return (FALSE);
}

int		join_from_purgatory(client * cli, zappy * zap, char * name)
{
  client *	purge_cli = list_find(zap->purgatory, name, &get_client_by_team);

  if (purge_cli)
    {
      list_remove_nofree(&zap->purgatory, purge_cli, &get_client_by_addr);
      purge_cli->socket = cli->socket;
      list_remove(&zap->client_list, cli, &get_client_by_socket);
      list_push_front(&zap->client_list, purge_cli);
      answer(response_ok(), purge_cli);
      printf(JOIN_PURGE_MSG, name);
      return (true);
    }
  return (false);
}

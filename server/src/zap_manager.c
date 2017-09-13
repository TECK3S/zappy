/*
** zap_manager.c for zap_manager.c in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/server
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Thu Jun  2 16:17:40 2011 eugene-valentin ngontang-tchiadjie
** Last update Tue Jul  5 21:37:15 2011 adrien barrau
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include "zappy.h"
#include "socket.h"

static inline int		poll_alloc(struct epoll_event * events, zappy * zap)
{
  struct epoll_event * temp;

  temp = realloc(events, (zap->max_clients + 11) * sizeof(*temp));
  if ( temp == NULL )
    {
      fprintf(stderr, "[System] Unable to reallocate memory\n");
      return (MEMORY_ERR_CODE);
    }
  zap->max_clients += 10;
  events = temp;
  return (NO_ERR_CODE);
}

static inline void	init_client(client * new_client, int sock)
{
  int		i = 0;

  new_client->socket = sock;
  new_client->team_name = NULL;
  new_client->pos.x = 0;
  new_client->pos.y = 0;
  new_client->current_act = 0;
  new_client->last_act = 0;
  new_client->state = CONNECTED;
  new_client->dir = UP;
  new_client->level = 1;
  new_client->read_buffer.begin = 0;
  new_client->read_buffer.end = 0;
  new_client->write_buffer.begin = 0;
  new_client->write_buffer.end = 0;
  new_client->num = 0;
  new_client->life = 0.0;
  for (; i < 7; ++i)
    new_client->inventory[i] = 0;
}

static inline int	add_client(zappy * zap,
				   int sock,
				   struct epoll_event * events)
{
  client *	new_client;
  int		errcode = NO_ERR_CODE;

  if ((new_client = malloc(sizeof(*new_client))) == NULL)
    return (-1);
  if (zap->current_clients >= zap->max_clients)
    errcode = poll_alloc(events, zap);
  if (!errcode)
    {
      init_client(new_client, sock);
      if (list_push_front(&zap->client_list, new_client) != TRUE)
	errcode = LIST_ADD_ERR_CODE;
    }
  if (!errcode)
    {
      printf("[System] A new client was connected and added\n");
      answer(response_bienvenue(), new_client);
    }
  return (errcode);
}

static inline int	check_event(zappy * zap,
				    struct epoll_event * event,
				    struct epoll_event * ev,
				    int epfd)
{
  int		errcode = NO_ERR_CODE;

  if (event->events & EPOLLRDHUP)
    errcode = purge_client(zap, event, ev, epfd);
  else
    errcode = get_command(zap, event->data.fd);
  return (errcode);
}

int		get_events(zappy * zap,
			   struct epoll_event *	events,
			   struct epoll_event *	ev,
			   int nfds,
			   int epfd)
{
  int		use = 0, errcode = NO_ERR_CODE;
  int		new_socket;
  struct sockaddr_in	new_address;

  while (use < nfds && use <= zap->max_clients)
    {
      if (events[use].data.fd == zap->socket)
	{
	  if ((new_socket = socket_create_connClient(zap->socket,
						     &new_address)) < 0)
	    errcode = ACCEPT_ERR_CODE;
	  else
	    {
	      ev->events = EPOLLIN | EPOLLRDHUP;
	      ev->data.fd = new_socket;
	      errcode = add_client(zap, new_socket, events);
	      if (!errcode && epoll_ctl(epfd, EPOLL_CTL_ADD, new_socket, ev) < 0)
		errcode = POLL_ERR_CODE;
	    }
	}
      else
	errcode = check_event(zap, &(events[use]), ev, epfd);
      ++use;
    }
  return (errcode);
}

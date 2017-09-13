/*
** zappy_server.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Jun  1 10:42:59 2011 adrien barrau
** Last update Tue Jul  5 21:44:01 2011 adrien barrau
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <signal.h>
#include "zappy.h"
#include "socket.h"

static inline int		enter_listen_mode(zappy * zap,
						  int * epfd,
						  struct epoll_event  * ev)
{
  int			listening = 0;

  *epfd = epoll_create1(0);
  if (*epfd == -1)
    {
      fprintf(stderr, "[System] Unable to create events poll\n");
      return (EPOLL_CREATE_ERR_CODE);
    }
  ev->events = EPOLLIN;
  ev->data.fd = zap->socket;
  if (epoll_ctl(*epfd, EPOLL_CTL_ADD, zap->socket, ev) == -1)
    {
      fprintf (stderr, "[System] Error in epoll_ctl on server socket\n");
      return (POLL_ERR_CODE);
    }
  if ((listening = listen(zap->socket, MAX_SIMULTANEOUS_CON)) == -1)
    {
      fprintf (stderr, "[System] Error in listen on the server socket\n");
      return (-1);
    }
  return (NO_ERR_CODE);
}

static inline int	init_fds(zappy * zap, int port, int * epfd,
				 struct epoll_event  * ev)
{
  int		errcode = NO_ERR_CODE;

  if ((zap->socket = socket_create_connServer(port)) < 0)
    errcode = SOCK_ERR_CODE;
  if (!errcode)
    errcode = enter_listen_mode(zap, epfd, ev);
  return (errcode);
}

static inline void	close_events(zappy * zap,
				     struct epoll_event * events,
				     int epfd,
				     struct epoll_event * ev)
{
  int			i = 0;

  for (i = 0; i <= zap->max_clients; ++i)
    if (epoll_ctl(epfd, EPOLL_CTL_DEL, events[i].data.fd, ev) == -1)
      fprintf(stderr, "[System] Error when removing socket from poll\n");
    else
      socket_close(events[i].data.fd);
}

int			zappy_server(zappy * zap, int port)
{
  extern bool		SERVER_ENDED;
  struct epoll_event	ev, *events;
  sigset_t		mask;
  int			errcode = 0, epfd = 0, nfds;

  if (sigfillset(&mask) == -1)
    errcode = SIGFILLLSET_ERR_CODE;
  if ((events = malloc((zap->max_clients + 1) * sizeof(*events))) == NULL)
    errcode = MEMORY_ERR_CODE;
  if (!errcode && init_fds(zap, port, &epfd, &ev) == NO_ERR_CODE)
    {
      while (!SERVER_ENDED)
	{
	  timize_actions(zap);
	  if ((nfds = epoll_pwait(epfd, events, zap->max_clients + 1,
				  zap->time_delay, &mask)) < 0)
	    continue;
	  else if (nfds > 0)
	    errcode = get_events(zap, events, &ev, nfds, epfd);
	  win_condition(zap);
	}
      close_events(zap, events, epfd, &ev);
    }
  free_all(zap, events);
  return (errcode);
}

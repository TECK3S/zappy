/*
** socket.c<2> for socket.c in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/server/doc/includes
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Thu Jun  2 12:18:21 2011 eugene-valentin ngontang-tchiadjie
** Last update Tue Jul  5 21:35:19 2011 adrien barrau
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "socket.h"

int		socket_write(buffer * b, int fd)
{
  int		n;
  int		write_size;
  char		buf[MAX_BUF_SIZE];

  n = MAX_BUF_SIZE - b->begin;
  if (b->begin <= b->end)
    {
      memcpy(buf, b->data + b->begin, b->end - b->begin);
      write_size = b->end - b->begin;
    }
  else
    {
      memcpy(buf, b->data + b->begin, n);
      memcpy(buf + n, b->data, b->end);
      write_size = n + b->end;
    }
  return (flush_buffer(b, buf, fd, write_size));
}

int		socket_read(buffer * b, int fd)
{
  int		n = 0;
  int		error = 0;
  char		buf[MAX_BUF_SIZE];

  n = read(fd, buf, MAX_BUF_SIZE);
  if ((n <= 0) && ((error = errno) != EINTR))
    return (-1);
  else if (error == EINTR)
    socket_read(b, fd);
  else
    fill_buffer(b, buf, n);
  return (n);
}

int			socket_create_connServer(int port)
{
  int			resu = 0;
  int			sockfd = 0;
  int			timeout = 0;
  int			opt = 1;
  struct protoent *	pe;
  struct sockaddr_in	server;

  if ((pe = getprotobyname("tcp")) == NULL)
    return (-1);
  if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    return (-1);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port);
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  while ((resu = bind(sockfd,
		      (struct sockaddr *) &server, sizeof(server))) < 0)
    {
      if (++timeout >= SRV_BIND_TIMEOUT)
	return (-1);
      sleep(1);
    }
  return (sockfd);
}

int		socket_create_connClient(const int serverfd,
					 const struct sockaddr_in * new_client)
{
  unsigned int		cli_length = 0;

  cli_length = sizeof(*new_client);
  return (my_accept(serverfd, (struct sockaddr *) &new_client, &cli_length));
}

int			socket_close(int fd)
{
  if (fd >= 0)
    {
      if (close(fd) < 0)
	{
	  fprintf(stderr, "[System] Unable close the socket\n");
	  return (-1);
	}
      return (0);
    }
  fprintf(stderr,
	  "[System] Unable close the socket, invalid file descriptor\n");
  return (-1);
}
